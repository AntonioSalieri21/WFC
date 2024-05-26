#ifndef TILE_INFO_H
#define TILE_INFO_H

#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

using std::string, std::vector;

struct TileInfo
{

    string tile_path;
    vector<string> sides;
    vector<vector<string>> rules;
    string ID;
    bool rotate = true;

    friend std::ostream& operator<<(std::ostream& os, const TileInfo& tile);
    

};
TileInfo rotateTileInfo(TileInfo tile, int steps, string newID);
#endif