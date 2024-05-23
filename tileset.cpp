#include "tileset.h"
#include <filesystem>
#include <iostream>
#include "sides.h"
Tileset::Tileset(string config_path): config(config_path)
{
    vector<TileInfo> tiles_info = config.getTilesInfo();
    
    for(TileInfo tile_info : tiles_info)
    {
        try{
            
            if(tile_info.rotate)
            {
                for(shared_ptr<Tile> tile_pointer : rotateTile(tile_info))
                    tiles.push_back(tile_pointer);
            }
            else
                tiles.push_back( std::make_shared<Tile>( tile_info) );
        }
        catch(std::exception& e)
        {
            std::cout << "Catched exception: " << e.what() << "\n";
        }
    }

    for( shared_ptr<Tile> tile : tiles)
    {
        
        tile->generateRules(tiles);
    }

}

vector< shared_ptr<Tile> >& Tileset::getTiles()
{
    return tiles;
}

shared_ptr<Tile> Tileset::getTile(string ID)
{
    for(shared_ptr<Tile> tile : tiles)
        if(tile->getId() == ID) return tile;

    return nullptr;
}

std::string removeFilename(const std::string& filepath) {
    std::filesystem::path p(filepath);
    p.remove_filename();
    return p.string();
}

vector<string> rotate(const vector<string>& sides, int count) 
{
    vector<string> rotatedSides = sides;

    std::rotate(rotatedSides.begin(), rotatedSides.begin()+rotatedSides.size() - count, rotatedSides.end());

    for(string side : rotatedSides)
        std::cout << side << " ";

    std::cout <<" Rotation: " << count*90 << "\n";

    return rotatedSides;
}

vector<shared_ptr<Tile>> Tileset::rotateTile(TileInfo info)
{
    /*
    UP 0
    RIGHT 1
    DOWN 2
    LEFT 3
    */

    vector<shared_ptr<Tile>> res;
    vector<TileInfo> infos;
    infos.push_back(info);
    
    TileInfo first_rotation = info;
    TileInfo second_rotation = info;
    TileInfo third_rotation = info;

    cv::Mat orig_mat = cv::imread(info.tile_path, cv::IMREAD_COLOR);
    cv::Mat first_rot_mat, second_rot_mat, third_rot_mat;

    cv::rotate(orig_mat, first_rot_mat, cv::ROTATE_90_CLOCKWISE);
    cv::rotate(orig_mat, second_rot_mat, cv::ROTATE_180);
    cv::rotate(orig_mat, third_rot_mat, cv::ROTATE_90_COUNTERCLOCKWISE);

    string first_path = removeFilename(info.tile_path) + info.ID + "_rotated90.png";
    string second_path = removeFilename(info.tile_path) + info.ID + "_rotated180.png";
    string third_path = removeFilename(info.tile_path) + info.ID + "_rotated270.png";

    cv::imwrite(first_path, first_rot_mat);
    cv::imwrite(second_path, second_rot_mat);
    cv::imwrite(third_path, third_rot_mat);

    vector<vector<string>> sides;
    sides.push_back(info.sides);
    for(int i = 1; i < 4; i++)
    {
        sides.push_back(rotate(info.sides, i));
    }

    infos.push_back({first_path,sides.at(1), info.ID + "_rotated90", true });
    infos.push_back({second_path,sides.at(2), info.ID + "_rotated180", true });
    infos.push_back({third_path,sides.at(3), info.ID + "_rotated270", true });

    std::cout << first_path << std::endl;

    for (const auto& info_l : infos) {
        res.push_back(std::make_shared<Tile>(info_l));
    }

    return res;

}
