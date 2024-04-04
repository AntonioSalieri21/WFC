#ifndef WFCGENERATOR_H
#define WFCGENERATOR_H

#include "tileset.h"
#include "grid.h"
#include <random>
#include "sides.h"

class WFCGenerator
{

    Grid& grid;
    Tileset& ts;

    Cell* initGrid();
    void updateGrid(Cell* changed_cell);
    Cell* collapseLeastEnthropy();

public:
    WFCGenerator(Grid& grid, Tileset& ts);
    ~WFCGenerator() = default;

    void collapseGrid();

};

#endif