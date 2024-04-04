#include "cell.h"
#include <iostream>
Cell::Cell(vector<int> tiles): tiles(tiles), enthropy(tiles.size())
{

}

void Cell::collapse()
{
    if(tiles.empty())
    {
        std::cout << "Cell is empty!" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, tiles.size()-1);


    enthropy = 1;
    int new_tile = tiles.at(distr(gen));
    tiles = vector<int> {new_tile};
}

vector<int> Cell::getTiles()
{
    return tiles;
}