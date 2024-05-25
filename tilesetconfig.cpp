#include "tilesetconfig.h"
#include <fstream>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <unordered_map>
#include <filesystem>

struct MatCompare
{
    bool operator()(const cv::Mat& a, const cv::Mat& b) const
    {
        return cv::norm(a, b, cv::NORM_L1) != 0;
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

vector<vector<cv::Mat>> splitImageIntoTiles(cv::Mat& img, int tileWidth, int tileHeight)
{
    vector<vector<cv::Mat>> tiles;
    int counter = 0;
    for(int y = 0; y < img.rows; y += tileHeight)
    {
        vector<cv::Mat> row;

        for(int x = 0; x < img.cols; x += tileWidth)
        {
            cv::Rect roi(x, y, tileWidth, tileHeight);
            cv::Mat tile = img(roi).clone(); // Ensure the tile is a continuous matrix
            row.push_back(tile);

            // Save each tile as a separate image
            std::string filename = "tile_" + std::to_string(counter) + ".png";
            cv::imwrite(filename, tile);
            counter++;
        }
        tiles.push_back(row);
    }

    return tiles;
}

vector<TileInfo> TilesetConfig::getTilesInfo()
{
    vector<TileInfo> res;
    if(config.contains("tiles"))
    {
        for(const auto& [key, tile] : config["tiles"].items())
        {
            res.push_back(TileInfo { tile["address"], tile["sides"], key, tile["rotate"]});
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

        vector<vector<cv::Mat>> tiles = splitImageIntoTiles(img, tileWidth, tileHeight);

        std::map<cv::Mat, std::pair<int, int>, MatCompare> tileMap;
        std::vector<std::vector<int>> tileIDs(tiles.size(), std::vector<int>(tiles[0].size()));
        int nextID = 0;

        for(int i = 0; i < tiles.size(); ++i)
        {
            for(int j = 0; j < tiles[i].size(); ++j)
            {
                auto& tile = tiles[i][j];
                auto it = tileMap.find(tile);

                if(it == tileMap.end())
                {
                    tileMap[tile] = {nextID, 1};
                    tileIDs[i][j] = nextID;
                    ++nextID;
                }
                else
                {
                    ++it->second.second;
                    tileIDs[i][j] = it->second.first;
                }
            }
        }


        for(auto row : tileIDs)
        {

            for(auto tile : row)
            {
                std::cout << tile << ' ';
            }
            std::cout << '\n';
        }
        

        











  
    }

    return res;
}
