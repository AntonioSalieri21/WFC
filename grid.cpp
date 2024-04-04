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
            row.push_back(Cell(tiles, j,i, ts));
        }
        cells.push_back(row);
    }

}

Cell* Grid::getCell(int x, int y)
{
    if(0 <= x < cells.size())
    {
        if( 0 <= y < cells.at(x).size())
            return &(cells.at(x).at(y));
    }

    return nullptr;
}

int Grid::getX()
{
    return x;
}

int Grid::getY()
{
    return y;
}

void Grid::printGridEnthropy()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            std::cout << getCell(i,j)->getTiles().size() << " ";
        std::cout << "\n";
    }
}
void Grid::printGridTiles()
{
    for(vector<Cell> row : cells)
    {
        for(Cell cell : row)
        {
            std::cout << "X: " << cell.getX();
            std::cout << " Y: " << cell.getY();
            std::cout << "  :  ";
            for(int id : cell.getTiles())
                std::cout << id << " ";
            std::cout << "\n";
        }
    }
}