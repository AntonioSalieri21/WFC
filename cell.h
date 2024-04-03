#ifndef CELL_H
#define CELL_H
#include <vector>

using std::vector;

class Cell
{

    int enthropy;
    vector<int> tiles;

public:
    Cell() = default;
    Cell(vector<int> tiles);
    ~Cell() = default;
    

};

#endif