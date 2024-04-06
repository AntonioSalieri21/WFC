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