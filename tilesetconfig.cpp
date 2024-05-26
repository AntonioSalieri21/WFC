
#include "tilesetconfig.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <filesystem>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

struct ImageCompare
{
    double threshold = 0.8;
    //Comparing magic here, totaly stolen from ChatGPT because I am not nearly smart enough to come up with this
    bool operator()(const shared_ptr<cv::Mat>& a_ptr, const shared_ptr<cv::Mat>& b_ptr) const 
    {
        cv::Mat a_gray, b_gray;
        cv::cvtColor(*a_ptr, a_gray, cv::COLOR_BGR2GRAY);
        cv::cvtColor(*b_ptr, b_gray, cv::COLOR_BGR2GRAY);

        cv::Mat ssim_map;
        cv::compare(a_gray, b_gray, ssim_map, cv::CMP_NE);

        double ssim_score = 1 - (double)cv::countNonZero(ssim_map) / (a_gray.size().width * a_gray.size().height);

        return ssim_score >= threshold; 
    }
};

TilesetConfig::TilesetConfig(string configPath)
{
    std::ifstream file(configPath);
    this->configPath = configPath;

    if(file.fail()){
        std::cerr << "Failed to open file." << '\n';
        return;
    }

    file >> config;
}


vector<cv::Mat> splitImageIntoGrid(cv::Mat& image, int x, int y) {
    vector<cv::Mat> gridImages;

    int subImageWidth = image.cols / x;
    int subImageHeight = image.rows / y;

    // Loop over the image grid
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            cv::Rect subImageSquare(j * subImageWidth, i * subImageHeight, subImageWidth, subImageHeight);

            cv::Mat subImage = image(subImageSquare);
            gridImages.push_back(subImage);
        }
    }

    return gridImages;
}

vector<TileInfo> TilesetConfig::getTilesInfo()
{
    vector<TileInfo> res;
    if(config["type"] != "auto")
    {
        for(const auto& [key, tile] : config["tiles"].items())
        {
            res.push_back(TileInfo { tile["address"], tile["sides"], vector<vector<string>>(), key, tile["rotate"]});
        }
    }
    else
    {
        /*
        Read config
        Open image
        Split image into tiles
        Count unique tiles and their frequencies
        Create rules for each tile
        Return them
        */

        //Read config
        std::filesystem::path config_path(configPath);
        string imagePath = config["path"];
        string directoryPath = config_path.parent_path();
        string path = directoryPath + "/" + imagePath; 
        int x = config["x"];
        int y = config["y"];
        bool rotate = config["rotate"];
        double threshold = config["threshold"];

        //Open image

        cv::Mat img = cv::imread(path, cv::IMREAD_COLOR); 

        //Split image into tiles

        vector<cv::Mat> gridImages = splitImageIntoGrid(img, x , y); //Creating grid

        map<int, shared_ptr<cv::Mat>> imageMap;
        map<int, int> countMap;
        vector<vector<int>> gridIDs(y, vector<int>(x, 0));

        int id = 0;
        ImageCompare comparer;
        comparer.threshold = threshold;



        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                shared_ptr<cv::Mat> tile = std::make_shared<cv::Mat>(gridImages[i * x + j]);

                //Oh God STL library syntaxis my favorite
                //Find if the tile is already in the map
                auto it = std::find_if(imageMap.begin(), imageMap.end(), 
                    [&tile, &comparer](const std::pair<int, shared_ptr<cv::Mat>>& p) { return comparer(p.second, tile); });
                if (it == imageMap.end()) {
                    imageMap[id] = tile;
                    countMap[id] = 1;
                    gridIDs[i][j] = id;
                    id++;
                } else { //Also we count the frequency of each tile for enthropy, but I forgot to implement it -\_('-')_/- 
                    countMap[it->first]++;
                    gridIDs[i][j] = it->first;
                }
            }
        }

        //Generating TileInfo without rules

        map<int, TileInfo> tileInfoMap;

        //C++17 thanks for multiplatform filesystem!
        std::filesystem::path directory = directoryPath + "/images";
        if(!std::filesystem::exists(directory)) 
        {
           std::filesystem::create_directories(directory);
        }
        else
        {
            std::filesystem::remove_all(directory);
            std::filesystem::create_directories(directory);
        }

        for (auto& pair : imageMap) {
            TileInfo info;
            info.ID = std::to_string(pair.first);
            info.tile_path = directoryPath + "/images/tile" + std::to_string(pair.first) + ".png";
            info.rotate = false;
            info.rules = vector<vector<string>>(4);

            cv::imwrite(info.tile_path, *pair.second);
            tileInfoMap[pair.first] = info;
        }

        //Generating rules
        //1. Generate rules for each tile
        //2. Fill in empty rules
        //3. Create rotation of those tiles

        for(int i = 0; i < gridIDs.size(); i++)
        {
            auto row = gridIDs[i];
            for(int j = 0; j < row.size(); j++)
            {
                int dirIndex = 0;
                auto currentTileIter = tileInfoMap.find(row.at(j));

                if (currentTileIter == tileInfoMap.end()) {
                    continue; 
                }

                for(auto dir : matrix_dir) //Generate rules for each tile
                {
                    int neighborI = i + dir.first;
                    int neighborJ = j + dir.second;

                    if(neighborI >= 0 && neighborI < gridIDs.size() 
                        && neighborJ >= 0 && neighborJ < row.size())
                    {
                        auto neighborTileIter = tileInfoMap.find(gridIDs.at(neighborI).at(neighborJ)); 

                        if (neighborTileIter == tileInfoMap.end()) {
                            continue; 
                        }

                        currentTileIter->second.rules.at(dirIndex).push_back(neighborTileIter->second.ID);
                    }

                    dirIndex++;
                }

                // Check for empty rules
                for(int dirIndex = 0; dirIndex < currentTileIter->second.rules.size(); dirIndex++)
                {
                    if(currentTileIter->second.rules.at(dirIndex).empty())
                    {
                        int oppositeSide = (dirIndex + 2) % 4; // Calculate the opposite side
                        currentTileIter->second.rules.at(dirIndex) = currentTileIter->second.rules.at(oppositeSide); // Copy rules from the opposite side

                        // Update the appropriate side of each neighbor tile
                        for(string tileID : currentTileIter->second.rules.at(oppositeSide))
                        {
                            auto tileIter = tileInfoMap.find(std::stoi(tileID));

                            if (tileIter != tileInfoMap.end()) {
                                tileIter->second.rules.at(oppositeSide).push_back(currentTileIter->second.ID);
                            }
                        }
                    }
                }
            }
        }         
        if(rotate) //Create rotation of those tiles
        {
            for(auto pair : tileInfoMap)
            {
                for(int i = 0; i < 4; i++)
                {
                    id++;
                    res.push_back(rotateTileInfo(pair.second, i, std::to_string(id)));
                }
                    
            }
        }


        for (auto& pair : tileInfoMap) {
            res.push_back(pair.second);
        }
    }

    return res;
}

