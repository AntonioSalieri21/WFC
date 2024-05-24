#ifndef TILE_INFO_H
#define TILE_INFO_H

#include <string>
#include <vector>
#include "pattern.h"
using std::string, std::vector, std::shared_ptr;

struct TileInfo
{

    string tile_path;
    vector<string> sides;
    vector<vector<int>> rules;
    string ID;
    bool rotate = true;

    friend std::ostream& operator<<(std::ostream& os, const TileInfo& tileInfo);



};



#endif