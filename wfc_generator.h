#ifndef WFCGENERATOR_H
#define WFCGENERATOR_H

#include "tileset.h"
#include "grid.h"
#include <random>
class WFCGenerator
{

    static void initGrid(Grid& grid);

public:
    static void collapseGrid(Grid& grid, Tileset& ts);

};

#endif