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
    vector<int> tiles;
    int x;
    int y;
    Tileset& ts;

public:
    Cell() = default;
    Cell(vector<int> tiles, int x, int y, Tileset& ts);
    ~Cell() = default;
    
    void collapse();
    void update(vector<string> rules, int direction);
    vector<int> getTiles();
    int getEnthropy(){return enthropy;}

    int getX() {return x;}
    int getY() {return y;}

};

#endif