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

    void rotateClockwise(int steps) {
        steps = steps % 4;
        for (int i = 0; i < steps; ++i) {
            rotateGridClockwise();
            rotateSidesClockwise();
            rotateNeighborsClockwise();
        }
    }

private:
    void rotateGridClockwise() {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> newGrid(m, vector<int>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                newGrid[j][n - 1 - i] = grid[i][j];
            }
        }
        grid = newGrid;
    }

    void rotateSidesClockwise() {
        vector<string> newSides(4);
        newSides[0] = sides[3]; // LEFT -> UP
        newSides[1] = sides[0]; // UP -> RIGHT
        newSides[2] = sides[1]; // RIGHT -> DOWN
        newSides[3] = sides[2]; // DOWN -> LEFT
        sides = newSides;
    }

    void rotateNeighborsClockwise() {
        vector<vector<int>> newNeighbors(4);
        newNeighbors[0] = neighbors[3]; // LEFT -> UP
        newNeighbors[1] = neighbors[0]; // UP -> RIGHT
        newNeighbors[2] = neighbors[1]; // RIGHT -> DOWN
        newNeighbors[3] = neighbors[2]; // DOWN -> LEFT
        neighbors = newNeighbors;
    }
};

#endif