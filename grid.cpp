#include "grid.h"

Grid::Grid(Tileset& ts, int x, int y): x(x), y(y)
{
    for(int i = 0; i < y; i++)
    {
        vector<Cell> row;
        for(int j = 0; j < x; j++)
        {
            vector<int> tiles;
            for(shared_ptr tile : ts.getTiles())
            {
                tiles.push_back(tile->getId());
            }
            row.push_back(Cell(tiles));
        }
    }

}

Cell* Grid::getCell(int x, int y)
{
    if(0 <= x < cells.size())
    {
        if( 0 <= y < cells.at(x).size())
            return &cells.at(x).at(y);
    }

    return nullptr;
}