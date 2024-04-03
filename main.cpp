#include "wfc_generator.h"
#include "tileset.h"
#include "grid.h"

int main(int argc, char *argv[])
{
    Tileset ts("/home/salieri/Study/C++/Project/SimpleTiles/config.json");
    Grid grid(ts, 4, 4);
    

    return 0;
}