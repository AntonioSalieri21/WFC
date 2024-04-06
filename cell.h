#ifndef CELL_H
#define CELL_H
#include <vector>
#include <random>
#include <string>
#include "sides.h"
#include <memory>
#include "tile.h"
#include "tileset.h"
using std::vector, std::string, std::shared_ptr;

class Cell
{

    int enthropy;
    vector<shared_ptr<Tile>> tiles;
    int x;
    int y;
    Tileset& ts;

public:
    Cell() = default;
    Cell(vector<shared_ptr<Tile>> tiles, int x, int y, Tileset& ts);
    ~Cell() = default;
    
    void collapse();
    bool update(vector<shared_ptr<Tile>> neigh_tiles, int direction);
    vector<shared_ptr<Tile>> getTiles() const;
    int getEnthropy()const{return enthropy;} 

    int getX()const {return x;} 
    int getY()const {return y;}
 
};

#endif