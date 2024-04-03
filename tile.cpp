#include "tile.h"
#include "sides.h"
Tile::Tile(TileInfo info, int ID) : sides(info.sides), ID(ID), address(info.tile_path)
{
    // image = cv::imread(info.tile_path, cv::IMREAD_COLOR);
    // if(!image.data) {
    //     std::cout << "Could not open or find the image." << std::endl;
    // }
    rules = vector< vector<int> >{4};
    
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
    //std::cout << "Checking tile: " << ID << " " << address << "\n";

    
    for(int dir : const_dir)
    {
        string checking_side = sides.at(dir);
        for( shared_ptr<Tile> tile : tiles)
        {
            string checked_side = tile->getSide(rotateSide(dir));
            
            if(checked_side == checking_side)
                rules.at(dir).push_back(tile->getId());

        }

    }

    // for(vector<int> rule: rules)
    // {
    //     for(int tile : rule)
    //         std::cout << tile << "\n";

    //     std::cout << "\n"; 
    // }
    // std::cout << "\n\n";    

}


string Tile::getSide(int side)
{
    return sides.at(side);
}

int Tile::getId()
{
    return ID;
}

std::ostream& Tile::operator<<(std::ostream& os)
{
    os << ID << ": \n";
    for(int dir : const_dir)
    {
        for(int tile:  rules.at(dir))
        {
            os << tile << " ";
        }
        os << "\n";
    }
    os << std::endl;

    return os;

}