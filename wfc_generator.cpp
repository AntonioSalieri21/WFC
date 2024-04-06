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
        grid.printGridEnthropy();
        for (int i : const_dir) {
            Cell* neighbor = nullptr;
            switch (i) {
                case UP:
                    neighbor = grid.getCell(current_cell->getX(), current_cell->getY()-1);
                    break;
                case RIGHT:
                    neighbor = grid.getCell(current_cell->getX()+1, current_cell->getY());
                    break;
                case DOWN:
                    neighbor = grid.getCell(current_cell->getX(), current_cell->getY()+1);
                    break;
                case LEFT:
                    neighbor = grid.getCell(current_cell->getX()-1, current_cell->getY());
                    break;
            }

            if (neighbor == nullptr || neighbor->getEnthropy() <= 1)
                continue;

            bool updated = neighbor->update(current_cell->getTiles(), i);

            if (updated) {
                cells_to_update.push(neighbor);
            }
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

Cell* WFCGenerator::collapseLeastEnthropy()
{
    Cell* res = grid.getLeastEnthropy();

    if(res == nullptr)
        return res;
    res->collapse();

    return res;
}