#ifndef TILESET_CONFIG_H
#define TILESET_CONFIG_H

#include <nlohmann/json.hpp>
#include <string> 
#include <vector>
#include "tileinfo.h"

using json = nlohmann::json;
using std::string, std::vector;

class TilesetConfig
{
    json config;

public:
    TilesetConfig(string config_path);
    ~TilesetConfig() = default;

    vector<TileInfo> getTilesInfo();
};

#endif