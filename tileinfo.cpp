#include "tileinfo.h"
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
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

TileInfo rotateTileInfo(TileInfo tile, int steps, string newID) {
    TileInfo newTile = tile;
    std::filesystem::path p = tile.tile_path;
    string directoryPath = p.parent_path().string();
    // Rotate image
    cv::Mat src = cv::imread(tile.tile_path);
    cv::Mat dst;
    vector<cv::RotateFlags> rotations{cv::ROTATE_90_CLOCKWISE, cv::ROTATE_180, cv::ROTATE_90_COUNTERCLOCKWISE};
    cv::rotate(src, dst, rotations[steps % 3]);

    newTile.tile_path = directoryPath + "/" + newID +  "rotated_" + std::to_string(90*steps) + ".png" ; // Update the tile_path with an appropriate name
    cv::imwrite(newTile.tile_path, dst);

    newTile.ID = newID;

    // Rotate rules
    std::rotate(newTile.rules.rbegin(), newTile.rules.rbegin() + steps, newTile.rules.rend());

    return newTile;
}