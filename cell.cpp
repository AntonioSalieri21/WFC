#include "cell.h"
#include <iostream>
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

vector<string> Cell::getTiles()
{
    return tiles;
}
bool Cell::update(vector<string> neigh_tiles, int direction)
{
    bool updated = false;
    int checking_side = rotateSide(direction); //Side to which we compare neighbouring tiles
    vector<string> new_tiles;

    for(string tileID : tiles) //For each possible tile in this cell
    {
        for(string nTile : neigh_tiles) //We take each possible tile from neighbopuring cell
        {
            vector<string> rule = ts.getTile(nTile)->getRules().at(direction); // Take possible neighbours for possible neigh tile

            if(std::find(rule.begin(), rule.end(), tileID) != rule.end() && 
            std::find(new_tiles.begin(), new_tiles.end(), tileID) == new_tiles.end()) //And if possible tile of this cell fullfills a rule 
                new_tiles.push_back(tileID); //We take it to an updated cell

        }
    }
    if(tiles == new_tiles)
        return false;

    tiles = new_tiles;
    enthropy = tiles.size();
    return true;
    // for(int tile : tiles)
    //     std::cout << tile << " ";
    // std::cout << "\n";

}