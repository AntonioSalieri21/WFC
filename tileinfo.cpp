#include "tileinfo.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const TileInfo& tileInfo)
{
    os << "Tile Path: " << tileInfo.tile_path << "\n";
    os << "Sides: ";
    for(const auto& side : tileInfo.sides)
    {
        os << side << " ";
    }
    os << "\nRules: \n";
    for(const auto& rule : tileInfo.rules)
    {
        for(const auto& num : rule)
        {
            os << num << " ";
        }
        os << "\n";
    }
    os << "ID: " << tileInfo.ID << "\n";
    os << "Rotate: " << (tileInfo.rotate ? "true" : "false") << "\n";
    return os;
}