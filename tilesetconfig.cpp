#include "tilesetconfig.h"
#include <fstream>
#include <iostream>

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
        string path = config["path"]; 
        int x = config["x"];
        int y = config["y"];
        bool rotate = config["rotate"];

        //Open image

        cv::Mat img = cv::imread(configPath + path, cv::IMREAD_COLOR); 

        //Split image into tiles
        int tileWidth = img.cols / x;
        int tileHeight = img.rows / y;

        








    }

    return res;
}
