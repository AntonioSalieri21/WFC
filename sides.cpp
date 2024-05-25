#include "sides.h"

int rotateSide(int side)
{
    return (side + 2) % 4;

}
int rotate90(int side)
{
    return (side + 1) % 4;
}
std::vector<int> const_dir {UP, RIGHT, DOWN, LEFT}; 
std::vector<std::pair<int,int>> matrix_dir { {-1, 0}, { 0, 1}, { 1 , 0}, { 0, -1 }  };