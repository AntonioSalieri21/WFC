#include "wfc_generator.h"
#include "tileset.h"
#include "grid.h"
#include "image_generator.h"
#include <iostream>
#include <memory>
#include <chrono>
using std::unique_ptr;
int main(int argc, char *argv[])
{
    if(argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <tileset name> <grid width> <grid height>\n";
        return 1;
    }

    int gridWidth = std::stoi(argv[2]);
    int gridHeight = std::stoi(argv[3]);
    string path = "../Tiles/" + std::string(argv[1]) + "/config.json";
    Tileset ts(path);
    
    unique_ptr<Grid> grid;
    do {

        grid.reset(new Grid(ts, gridWidth, gridHeight));

        WFCGenerator generator(*grid, ts);
        auto start = std::chrono::high_resolution_clock::now();

        generator.collapseGrid();

        auto end = std::chrono::high_resolution_clock::now(); 
        std::chrono::duration<double> elapsed = end - start;

        std::cout << "Time taken to collapse grid: " << elapsed.count() << " seconds\n";
        std::cout << std::endl;
        
    } while(!grid->isValid());
    ImageGenerator::saveImage(*grid, ts, "image.png");
    
    return 0;
}