#include "wfc_generator.h"
#include "tileset.h"
#include "grid.h"
#include <iostream>
int main(int argc, char *argv[])
{
    Tileset ts("../SimpleTiles/config.json");
    Grid grid(ts, 4, 4);
    WFCGenerator generator(grid, ts);
    generator.collapseGrid();

    grid.printGridEnthropy();
    grid.printGridTiles();
    return 0;
}