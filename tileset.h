#ifndef TILESET_H
#define TILESET_H

#include <vector>
#include "tile.h"
#include <string>
#include <memory>
#include "tilesetconfig.h"
#include "tileinfo.h"
#include <memory>

using std::vector, std::string, std::shared_ptr;

class Tile;

class Tileset
{

    vector<shared_ptr<Tile>> tiles;
    TilesetConfig config;
public:
    Tileset() = default;
    Tileset(string config_path);
    ~Tileset() = default;

    vector< shared_ptr<Tile> >& getTiles();
    shared_ptr<Tile> getTile(int ID);
};

#endif