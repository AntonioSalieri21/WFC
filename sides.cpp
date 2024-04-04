#include "sides.h"

int rotateSide(int side)
{
    int res = side + 2;
    if(res > LEFT)
        res -= LEFT+1;

    return res;

}
int rotate90(int side)
{
    return (side + 1) % 4;
}
std::vector<int> const_dir {UP, RIGHT, DOWN, LEFT}; 