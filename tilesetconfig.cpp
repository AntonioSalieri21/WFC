#include "tilesetconfig.h"
#include <fstream>
#include <iostream>

TilesetConfig::TilesetConfig(string config_path)
{
    std::ifstream file(config_path);

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

    return res;
}
