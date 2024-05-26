#ifndef TILESET_CONFIG_H
#define TILESET_CONFIG_H

#include <nlohmann/json.hpp>
#include <string> 
#include <vector>
#include "tileinfo.h"
#include <memory>
#include <opencv2/opencv.hpp>
#include "sides.h"
using json = nlohmann::json;
using std::string, std::vector, std::shared_ptr, std::map;

struct TileTMP
{
    shared_ptr<cv::Mat> tile;
    int ID;
    int quantity;
};

class TilesetConfig
{
    json config;
    string configPath;

public:
    TilesetConfig(string configPath);
    ~TilesetConfig() = default;

    vector<TileInfo> getTilesInfo();
};

#endif