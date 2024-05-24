#include "sides.h"
#include <algorithm>
int rotateSide(int side)
{
    return (side + 2) % 4;

}
int rotate90(int side)
{
    return (side + 1) % 4;
}
std::vector<int> const_dir {UP, RIGHT, DOWN, LEFT}; 

std::string reverseString(const std::string& str) 
{
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    return reversedStr;
}