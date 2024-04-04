#ifndef SIDES_H
#define SIDES_H

#include <vector>

constexpr int UP = 0; //1
constexpr int RIGHT = 1; // 2
constexpr int DOWN = 2; //3
constexpr int LEFT = 3;//4

int rotateSide(int side);
int rotate90(int side);

extern std::vector<int> const_dir; 

#endif