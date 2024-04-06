#include "grid.h"

Grid::Grid(Tileset& ts, int x, int y): xSize(x), ySize(y)
{

    vector<shared_ptr<Tile>> ts_tiles = ts.getTiles();
    for(int i = 0; i < y; i++) // row
    {
        vector<Cell> row;
        for(int j = 0; j < x; j++) // column
        {
            vector<shared_ptr<Tile>> tiles = ts_tiles;
            row.push_back(Cell(tiles, j,i, ts));
        }
        cells.push_back(row);
    }

}

Cell* Grid::getCell(int x, int y) 
{
    if(y >= 0 & y < cells.size())
    {
        if( x >= 0 && x < cells[y].size())
            return &(cells[y][x]);
    }

    return nullptr;
}

bool Grid::isCollapsed() 
{
    for(const vector<Cell>& row : cells)
    {
        for(const Cell& cell : row)
            if(cell.getEnthropy() != 1) return false; 
    }
    return true;
}

Cell* Grid::getLeastEnthropy() 
{
    Cell* res = nullptr;
    for(int i = 0; i < ySize; i++)
    {
        for(int j = 0; j < xSize; j++)
        {
            Cell* tmp = getCell(j,i);
            if(tmp->getEnthropy() > 1)
            {
                if(res == nullptr)
                    res = tmp;
                else if (res->getEnthropy() > tmp->getEnthropy())
                    res = tmp;
            }
        }
    }
    return res;

}

bool Grid::isValid() const
{
    for(const vector<Cell> row : cells)
    {
        for(const Cell cell : row)
            if(cell.getEnthropy() < 1) return false; 
    }
    return true;
}


void Grid::printGridEnthropy() 
{
    for(int i = 0; i < ySize; i++)
    {
        for(int j = 0; j < xSize; j++)
            std::cout << getCell(j,i)->getEnthropy() << " ";
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
            for(shared_ptr<Tile> tile : cell.getTiles())
                std::cout << tile->getId() << " ";
            std::cout << "\n";
        }
    }
}

void Grid::printGridCollapsedTiles() 
{
    for(int i = 0; i < ySize; i++)
    {
        for(int j = 0; j < xSize; j++)
        {
            if(getCell(j,i)->getEnthropy() == 1)
                std::cout << getCell(j,i)->getTiles().at(0) << " ";
            else
                std::cout << "N ";
        }
        std::cout << "\n";
    }
}