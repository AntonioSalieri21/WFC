#include "sides.h"

int rotateSide(int side)
{
    int res = side + 2;
    if(res > LEFT)
        res -= LEFT+1;

    return res;

}
std::vector<int> const_dir {UP, RIGHT, DOWN, LEFT}; 