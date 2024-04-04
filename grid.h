#ifndef GRID_H
#define GRID_H

#include <vector>
#include "cell.h"
#include "tileset.h"

using std::vector;

class Grid
{
    int xSize; // column
    int ySize; // row
    vector<vector<Cell>> cells;

public:
    Grid() = default;
    Grid(Tileset& ts, int x, int y);
    ~Grid() = default;

    Cell* getCell(int x, int y);
    int getX();
    int getY();
    bool isCollapsed();
    bool isValid();
    Cell* getLeastEnthropy();
    vector<vector<Cell>>& getCells(){return cells;}

    void printGridEnthropy();
    void printGridTiles();
    void printGridCollapsedTiles();

};

#endif