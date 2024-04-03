#include "tilesetconfig.h"
#include <fstream>
#include <iostream>

TilesetConfig::TilesetConfig(string config_path)
{
    std::ifstream file;
    try
    {
        file.open(config_path);
    }
    catch(const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    file >> config;
}

vector<TileInfo> TilesetConfig::getTilesInfo()
{
    vector<TileInfo> res;

    if(config.contains("tiles"))
    {
        for(const auto& tile : config["tiles"])
        {
            res.push_back(TileInfo { tile["address"], tile["sides"]});
            
        }
            
    }

    return res;
}

