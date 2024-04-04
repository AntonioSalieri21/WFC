#ifndef CELL_H
#define CELL_H
#include <vector>
#include <random>
using std::vector;

class Cell
{

    int enthropy;
    vector<int> tiles;

public:
    Cell() = default;
    Cell(vector<int> tiles);
    ~Cell() = default;
    
    void collapse();
    vector<int> getTiles();

};

#endif