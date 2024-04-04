#include "wfc_generator.h"
#include <queue>

using std::queue;

WFCGenerator::WFCGenerator(Grid& grid, Tileset& ts): grid(grid), ts(ts) 
{

}
void WFCGenerator::collapseGrid()
{

    Cell* changed_cell = initGrid();

    int steps = 0;

    while(!grid.isCollapsed())
    {
        updateGrid(changed_cell);

        std::cout << "Step: " << steps << "\n";
        steps++;
        grid.printGridEnthropy();

        changed_cell = collapseLeastEnthropy();
        if(changed_cell == nullptr)
            break;


    }
    std::cout << std::endl;


}

void WFCGenerator::updateGrid(Cell* changed_cell)
{
    std::queue<Cell*> cells_to_update;
    cells_to_update.push(changed_cell);

    while (!cells_to_update.empty()) {
        Cell* current_cell = cells_to_update.front();
        cells_to_update.pop();

        vector<Cell*> neighbors(4);
        neighbors.at(UP) = grid.getCell(current_cell->getX(), current_cell->getY()-1);
        neighbors.at(RIGHT) = grid.getCell(current_cell->getX()+1, current_cell->getY());
        neighbors.at(DOWN) = grid.getCell(current_cell->getX(), current_cell->getY()+1);
        neighbors.at(LEFT) = grid.getCell(current_cell->getX()-1, current_cell->getY());

        for (int i : const_dir) {
            if (neighbors.at(i) == nullptr || neighbors.at(i)->getEnthropy() <= 1)
                continue;

            bool updated = neighbors.at(i)->update(current_cell->getTiles(), i);

            if (updated) {
                cells_to_update.push(neighbors.at(i));
            }
        }
    }
}

// void WFCGenerator::updateGrid(Cell* changed_cell)
// {
//     vector<Cell*> neigh(4);
//     neigh.at(UP) = grid.getCell(changed_cell->getX(), changed_cell->getY()-1);
//     neigh.at(RIGHT) = grid.getCell(changed_cell->getX()+1, changed_cell->getY());
//     neigh.at(DOWN) = grid.getCell(changed_cell->getX(), changed_cell->getY()+1);
//     neigh.at(LEFT) = grid.getCell(changed_cell->getX()-1, changed_cell->getY());
//     for(int i : const_dir)
//     {    
//         if(neigh.at(i) == nullptr || neigh.at(i)->getEnthropy() <= 1)
//             continue;

//         neigh.at(i)->update(changed_cell->getTiles(), i);


//     }
 
// }

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

Cell* WFCGenerator::collapseLeastEnthropy()
{
    Cell* res = grid.getLeastEnthropy();
    //std::cout << res << "\n";
    if(res == nullptr)
        return res;
    res->collapse();

    return res;
}