#ifndef WFCGENERATOR_H
#define WFCGENERATOR_H

#include "tileset.h"
#include "grid.h"

class WFCGenerator
{

public:
    static void collapseGrid(Grid& grid, Tileset& ts);

};

#endif