#ifndef SIDES_H
#define SIDES_H

#include <vector>

constexpr int UP = 0; //1
constexpr int RIGHT = 1; // 2
constexpr int DOWN = 2; //3
constexpr int LEFT = 3;//4

int rotateSide(int side)
{
    int res = side + 2;
    if(res > LEFT)
        res -= LEFT+1;

    return res;

}

std::vector<int> const_dir {UP, RIGHT, DOWN, LEFT}; 

#endif