#include "tile.h"
#include "sides.h"
Tile::Tile(TileInfo info) : sides(info.sides), ID(info.ID), address(info.tile_path)
{
    image = cv::imread(info.tile_path, cv::IMREAD_COLOR);
    if(!image.data) {
        std::cout << "Could not open or find the image." << std::endl;
    }
    rules = vector< vector<string> >(4);
    std::cout << "ID " << ID << ": " << address << "\n";
}

Tile::~Tile()
{
}
std::string reverseString(const std::string& str) 
{
    std::string reversedStr = str;
    std::reverse(reversedStr.begin(), reversedStr.end());
    return reversedStr;
}
void Tile::generateRules(vector<shared_ptr<Tile>>& tiles)
{
    /*
    UP
    RIGHT
    DOWN
    LEFT
    */
    
    for(int dir : const_dir)
    {
        string checking_side = sides.at(dir);
        for( shared_ptr<Tile> tile : tiles)
        {
            string checked_side = reverseString(tile->getSide(rotateSide(dir)));
            if(checked_side == checking_side)
                rules.at(dir).push_back(tile->getId());

        }

    }

}


string Tile::getSide(int side)
{
    return sides.at(side);
}

string Tile::getId()
{
    return ID;
}

std::ostream& Tile::operator<<(std::ostream& os)
{
    os << ID << ": \n";
    for(int dir : const_dir)
    {
        for(string tile:  rules.at(dir))
        {
            os << tile << " ";
        }
        os << "\n";
    }
    os << std::endl;

    return os;

}