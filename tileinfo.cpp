#include "tileinfo.h"
#include <iostream>
#include <vector>
#include <string>
std::ostream& operator<<(std::ostream& os, const TileInfo& tile) {
    os << "TileInfo { ID: " << tile.ID
    << ", tile_path: " << tile.tile_path
    << ", rotate: " << (tile.rotate ? "true" : "false")
    << ", sides: [";
    for (const auto& side : tile.sides) {
        os << side << ", ";
    }
    os << "], rules: [";
    for (const auto& rule : tile.rules) {
        os << "[";
        for (const auto& r : rule) {
            os << r << ", ";
        }
        os << "], ";
    }
    os << "] }";
    return os;
}