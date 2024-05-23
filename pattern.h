#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include <string>
#include <memory>

using std::vector, std::string, std::shared_ptr;
class Pattern 
{

public:
    vector<vector<int>> grid;
    vector<string> sides;
    vector<shared_ptr<Pattern>> neighbors; 

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

        // DOWN
        for (int i = 0; i < grid.back().size(); ++i) {
            sides[2] += std::to_string(grid.back()[i]);
        }

        // LEFT
        for (int i = 0; i < grid.size(); ++i) {
            sides[3] += std::to_string(grid[i].front());
        }
    }

    Pattern(vector<vector<int>> grid) : grid(grid)
    {

        generateSides();


    }

    void addNeighbor(std::shared_ptr<Pattern> neighbor) {
        neighbors.push_back(neighbor);
    }
};

#endif