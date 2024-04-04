#ifndef TILE_INFO_H
#define TILE_INFO_H

#include <string>
#include <vector>
using std::string, std::vector;

struct TileInfo
{

    string tile_path;
    vector<string> sides;
    string ID;
    bool rotate = true;

};

#endif