#ifndef TILE_INFO_H
#define TILE_INFO_H

#include <string>
#include <vector>
using std::string, std::vector, std::shared_ptr;

struct TileInfo
{

    string tile_path;
    vector<string> sides;
    vector<shared_ptr<int>> rulesById;
    string ID;
    bool rotate = true;

};

#endif