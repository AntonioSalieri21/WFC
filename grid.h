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
    Grid(Tileset& ts, int x, int y);
    ~Grid() = default;

    Cell* getCell(int x, int y);
    int getX()const{return xSize;}
    int getY()const{return ySize;}
    bool isCollapsed();
    bool isValid()const;
    Cell* getLeastEnthropy();
    vector<vector<Cell>>& getCells(){return cells;}

    void printGridEnthropy();
    void printGridTiles();
    void printGridCollapsedTiles();

};

#endif