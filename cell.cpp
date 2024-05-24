#include "cell.h"
#include <iostream>
#include <unordered_set>
using std::unordered_set;
Cell::Cell(vector<shared_ptr<Tile>> tiles, int x, int y, Tileset& ts):
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
    shared_ptr<Tile> new_tile = tiles.at(distr(gen));
    tiles = vector<shared_ptr<Tile>> {new_tile};
}

vector<shared_ptr<Tile>> Cell::getTiles() const
{
    return tiles;
}

bool Cell::update(vector<shared_ptr<Tile>> neigh_tiles, int direction)
{
    bool updated = false;
    int checking_side = rotateSide(direction); //Side to which we compare neighbouring tiles
    unordered_set<shared_ptr<Tile>> new_tiles;

    for(shared_ptr<Tile> neigh_tile : neigh_tiles) //We take pointer to each possible tile from neighbopuring cell
    {
        vector<string> rule = neigh_tile->getRules().at(direction); // Take possible neighbours for possible neigh tile

        for(shared_ptr<Tile> possible_tile : tiles) //For each possible tile in this cell
        {
            if(std::find(rule.begin(), rule.end(), possible_tile->getId()) != rule.end())
                new_tiles.insert(possible_tile); //We take it to an updated cell        
            
        }
    }

    if(tiles.size() == new_tiles.size())
        return false;

    tiles.assign(new_tiles.begin(), new_tiles.end());

    enthropy = tiles.size();
    return true;
}
