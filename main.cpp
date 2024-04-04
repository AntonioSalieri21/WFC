#include "wfc_generator.h"
#include "tileset.h"
#include "grid.h"
#include <iostream>
int main(int argc, char *argv[])
{
    Tileset ts("../SimpleTiles/config.json");
    Grid grid(ts, 4, 4);
    WFCGenerator::collapseGrid(grid, ts);

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            std::cout << grid.getCell(i,j)->getTiles().size() << " ";
        std::cout << "\n";
    }

    return 0;
}