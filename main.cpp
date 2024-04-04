#include "wfc_generator.h"
#include "tileset.h"
#include "grid.h"
#include "image_generator.h"
#include <iostream>
#include <memory>

using std::unique_ptr;
int main(int argc, char *argv[])
{
    Tileset ts("../SimpleTiles/config.json");
    
    unique_ptr<Grid> grid;
    do {
        grid.reset(new Grid(ts, 4, 4));
        WFCGenerator generator(*grid, ts);
        generator.collapseGrid();

        //grid.printGridEnthropy();
        //grid.printGridTiles();
        grid->printGridCollapsedTiles();
        
    } while(!grid->isValid());
    ImageGenerator::saveImage(*grid, ts, "image.png");
    
    return 0;
}