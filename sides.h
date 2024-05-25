#ifndef SIDES_H
#define SIDES_H

#include <vector>

const int UP = 0; //1
const int RIGHT = 1; // 2
const int DOWN = 2; //3
const int LEFT = 3;//4

int rotateSide(int side);
int rotate90(int side);

extern std::vector<int> const_dir; 
extern std::vector<std::pair<int,int>> matrix_dir;

#endif