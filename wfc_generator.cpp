#include "wfc_generator.h"
#include <queue>

using std::queue;

WFCGenerator::WFCGenerator(Grid& grid, Tileset& ts): grid(grid), ts(ts) 
{

}
void WFCGenerator::collapseGrid()
{

    Cell* changed_cell = initGrid();
    std::cout<<changed_cell->getX() << std::endl;
    updateGrid(changed_cell);


}

void WFCGenerator::updateGrid(Cell* changed_cell)
{
    vector<Cell*> visited; //REPLACE WITH HASH MAP
    queue<Cell*> order;
    order.push(changed_cell);

    std::cout << order.front() << "\n";
    while(order.size() > 0)
    {
        Cell* current_cell = order.front();
        order.pop();

        vector<Cell*> neigh(4);
        neigh[0] = grid.getCell(changed_cell->getX(), changed_cell->getY()-1);
        neigh[1] = grid.getCell(changed_cell->getX()+1, changed_cell->getY());
        neigh[2] = grid.getCell(changed_cell->getX(), changed_cell->getY()+1);
        neigh[3] = grid.getCell(changed_cell->getX()-1, changed_cell->getY());

        // std::cout << neigh.at(0)->getTiles().size() << "\n";
        // std::cout << neigh.at(RIGHT)->getTiles().size() << "\n";
        // std::cout << neigh.at(DOWN)->getTiles().size() << "\n";
        // std::cout << neigh.at(LEFT)->getTiles().size() << "\n";
        for(int i : const_dir)
        {
            if(neigh.at(i) == nullptr)
                continue;

            if(std::find(visited.begin(), visited.end(), neigh.at(i)) != visited.end())
                continue;

            vector<string> rules;
            for(int tileID : current_cell->getTiles())
            {
                shared_ptr<Tile> tile = ts.getTile(tileID);
                rules.push_back(tile->getSide(i));
            }

            neigh.at(i)->update(rules, i);
            visited.push_back(neigh.at(i));
            order.push(neigh.at(i));
            std::cout << order.front() << "\n";

        }


    }

}

Cell* WFCGenerator::initGrid()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distr(0, grid.getX()-1);
    int x = distr(gen);
    distr = std::uniform_int_distribution<>(0, grid.getY()-1);
    int y = distr(gen);

    Cell* collapsed_cell = grid.getCell(x,y);

    if(collapsed_cell == nullptr)
    {
        std::cout << "Cell not found!" << std::endl;
    }
    else
        collapsed_cell->collapse();

    return collapsed_cell;

}