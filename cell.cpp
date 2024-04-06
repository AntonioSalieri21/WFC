#include "cell.h"
#include <iostream>
#include <unordered_set>
using std::unordered_set;
Cell::Cell(vector<string> tiles, int x, int y, Tileset& ts):
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
    string new_tile = tiles.at(distr(gen));
    tiles = vector<string> {new_tile};
}

vector<string> Cell::getTiles() const
{
    return tiles;
}

bool Cell::update(vector<string> neigh_tiles, int direction)
{
    bool updated = false;
    int checking_side = rotateSide(direction); //Side to which we compare neighbouring tiles
    unordered_set<string> new_tiles;

    for(string nTile : neigh_tiles) //We take each possible tile from neighbopuring cell
    {
        vector<string> rule = ts.getTile(nTile)->getRules().at(direction); // Take possible neighbours for possible neigh tile

        for(string tileID : tiles) //For each possible tile in this cell
        {
            if(std::find(rule.begin(), rule.end(), tileID) != rule.end()) //And if possible tile of this cell fullfills a rule 
                new_tiles.insert(tileID); //We take it to an updated cell
        }
    }

    if(tiles.size() == new_tiles.size() && std::all_of(new_tiles.begin(), new_tiles.end(), [this](const string& tile){ return std::find(tiles.begin(), tiles.end(), tile) != tiles.end(); }))
        return false;

    tiles.assign(new_tiles.begin(), new_tiles.end());
    enthropy = tiles.size();
    return true;
}
