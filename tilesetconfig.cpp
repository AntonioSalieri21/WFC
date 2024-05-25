#include "tilesetconfig.h"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <filesystem>

struct MatCompare
{
    bool operator()(const std::shared_ptr<cv::Mat>& a_ptr, const std::shared_ptr<cv::Mat>& b_ptr) const
    {
        cv::Mat a_resized, b_resized;
        cv::resize(*a_ptr, a_resized, cv::Size(8, 8), 0, 0, cv::INTER_AREA);
        cv::resize(*b_ptr, b_resized, cv::Size(8, 8), 0, 0, cv::INTER_AREA);

        cv::Mat a_gray, b_gray;
        cv::cvtColor(a_resized, a_gray, cv::COLOR_BGR2GRAY);
        cv::cvtColor(b_resized, b_gray, cv::COLOR_BGR2GRAY);

        uint64_t a_hash = 0, b_hash = 0;
        double a_mean = cv::mean(a_gray)[0];
        double b_mean = cv::mean(b_gray)[0];

        for (int i = 0; i < a_gray.rows; ++i)
        {
            for (int j = 0; j < a_gray.cols; ++j)
            {
                a_hash <<= 1;
                a_hash |= (a_gray.at<uchar>(i, j) > a_mean) ? 1 : 0;

                b_hash <<= 1;
                b_hash |= (b_gray.at<uchar>(i, j) > b_mean) ? 1 : 0;
            }
        }

        return a_hash != b_hash;
    }
};

TilesetConfig::TilesetConfig(string config_path)
{
    std::ifstream file(config_path);
    configPath = config_path;

    if(file.fail()){
        std::cerr << "Failed to open file." << '\n';
        return;
    }

    file >> config;
}


vector<cv::Mat> splitImageIntoGrid(cv::Mat& image, int x, int y) {
    vector<cv::Mat> gridImages;

    // Calculate the size of each sub-image
    int subImageWidth = image.cols / x;
    int subImageHeight = image.rows / y;

    // Loop over the image grid
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            // Define the ROI for this grid cell
            cv::Rect roi(j * subImageWidth, i * subImageHeight, subImageWidth, subImageHeight);

            // Extract the sub-image and add it to the vector
            cv::Mat subImage = image(roi);
            gridImages.push_back(subImage);
        }
    }

    return gridImages;
}

vector<TileInfo> TilesetConfig::getTilesInfo()
{
    vector<TileInfo> res;
    if(config.contains("tiles"))
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

        //Open image

        cv::Mat img = cv::imread(path, cv::IMREAD_COLOR); 

        //Split image into tiles
        int tileWidth = img.cols / x;
        int tileHeight = img.rows / y;

        vector<cv::Mat> gridImages = splitImageIntoGrid(img, x , y); //Creating grid

        std::map<int, cv::Mat> imageMap;
        std::map<int, int> countMap;
        std::vector<std::vector<int>> gridIDs(y, std::vector<int>(x, 0));

        int id = 0;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                cv::Mat tile = gridImages[i * x + j];
                auto it = std::find_if(imageMap.begin(), imageMap.end(), 
                    [&tile](const std::pair<int, cv::Mat>& p) { return cv::norm(p.second, tile) == 0; });
                if (it == imageMap.end()) {
                    imageMap[id] = tile;
                    countMap[id] = 1;
                    gridIDs[i][j] = id;
                    id++;
                } else {
                    countMap[it->first]++;
                    gridIDs[i][j] = it->first;
                }
            }
        }

        for (const auto &row : gridIDs) {
            for (const auto &elem : row) {
                std::cout << elem << ' ';
            }
            std::cout << '\n';
        }
        //Generating TileInfo without rules

        std::map<int, TileInfo> tileInfoMap;

        for (const auto& pair : imageMap) {
            TileInfo info;
            info.ID = std::to_string(pair.first);
            info.tile_path = directoryPath + "/tile" + std::to_string(pair.first) + ".png";
            info.rotate = false;
            info.rules = vector<vector<string>>(4);

            cv::imwrite(info.tile_path, pair.second);
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
                    continue; // or handle the error
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
                            continue; // or handle the error
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



        for (auto& pair : tileInfoMap) {
            res.push_back(pair.second);
            std::cout << pair.second << "\n";


        }

  
    }

    return res;
}
