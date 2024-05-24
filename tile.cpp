#include "tile.h"
#include "sides.h"
Tile::Tile(TileInfo info) : sides(info.sides), ID(info.ID), address(info.tile_path)
{
    image = cv::imread(info.tile_path, cv::IMREAD_COLOR);
    if(!image.data) {
        std::cout << "Could not open or find the image." << std::endl;
    }

    if(info.rules.size() > 0)
    {
        for(const auto& rule : info.rules)
        {
            vector<string> temp;
            for(const auto& r : rule)
            {
                temp.push_back(std::to_string(r));
            }
            rules.push_back(temp);
        }
    }
    else
        rules = vector< vector<string> >(4);
    std::cout << "ID " << ID << ": " << address << "\n";
}

Tile::~Tile()
{
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

std::ostream& operator<<(std::ostream& os, const Tile& tile)
{
    os << "Tile ID: " << tile.ID << "\n";
    os << "Image Address: " << tile.address << "\n";
    os << "Sides: ";
    for(const auto& side : tile.sides)
    {
        os << side << " ";
    }
    os << "\nRules:\n";
    for(const auto& rule : tile.rules)
    {
        for(const auto& r : rule)
        {
            os << r << " ";
        }
        os << "\n";
    }
    return os;
}