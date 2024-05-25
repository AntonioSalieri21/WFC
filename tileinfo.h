#ifndef TILE_INFO_H
#define TILE_INFO_H

#include <string>
#include <vector>
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

#endif