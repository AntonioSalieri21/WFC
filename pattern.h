#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include <string>
#include <memory>
#include <algorithm>

using std::vector, std::string, std::shared_ptr;
class Pattern 
{

public:

    int ID;
    vector<vector<int>> grid;
    vector<string> sides;
    vector<vector<int>> neighbors; 

    Pattern(vector<vector<int>> grid, int ID) : grid(grid), ID(ID) {
        sides = vector<string>(4);
        neighbors.resize(4);
        generateSides();
    }
    ~Pattern()=default;

    void generateSides()
    {
        // UP
        for (int i = 0; i < grid[0].size(); ++i) {
            sides[0] += std::to_string(grid[0][i]);
        }

        // RIGHT
        for (int i = 0; i < grid.size(); ++i) {
            sides[1] += std::to_string(grid[i].back());
        }

        // DOWN (reversed)
        for (int i = grid.back().size() - 1; i >= 0; --i) {
            sides[2] += std::to_string(grid.back()[i]);
        }

        // LEFT (reversed)
        for (int i = grid.size() - 1; i >= 0; --i) {
            sides[3] += std::to_string(grid[i].front());
        }
    }

    void addNeighbor(int ID, int dir)
    {
        auto it = std::find(neighbors.at(dir).begin(), neighbors.at(dir).end(), ID);

        if (it == neighbors.at(dir).end()) {
            neighbors.at(dir).push_back(ID);
        }
    }
};

#endif