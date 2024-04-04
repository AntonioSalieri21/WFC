#ifndef GRID_H
#define GRID_H

#include <vector>
#include "cell.h"
#include "tileset.h"

using std::vector;

class Grid
{
    int x;
    int y;
    vector<vector<Cell>> cells;

public:
    Grid() = default;
    Grid(Tileset& ts, int x, int y);
    ~Grid() = default;

    Cell* getCell(int x, int y);
    int getX();
    int getY();

    void printGridEnthropy();
    void printGridTiles();

};

#endif