#include "cell.h"
#include <iostream>
Cell::Cell(vector<int> tiles, int x, int y, Tileset& ts):
 tiles(tiles), enthropy(tiles.size()), 
 x(x), y(y), ts(ts)
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
void Cell::update(vector<string> rules, int direction)
{

    int checking_side = rotateSide(direction);
    vector<int> new_tiles;
    for(int tileID : tiles)
    {
        bool satisfied_check = false;
        shared_ptr<Tile> tile = ts.getTile(tileID);
        string side = tile->getSide(checking_side);
        for(string rule : rules)
        {
            if(rule == side)
            {
                satisfied_check = true;
                break;
            }
        }
        if(satisfied_check)
            new_tiles.push_back(tileID);
    }
    tiles = new_tiles;
    enthropy = tiles.size();
    std::cout << enthropy << "\n";

}