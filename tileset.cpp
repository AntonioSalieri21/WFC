#include "tileset.h"
#include <filesystem>
#include <iostream>

Tileset::Tileset(string config_path): config(config_path)
{
    vector<TileInfo> tiles_info = config.getTilesInfo();
    
    for(TileInfo tile_path : tiles_info)
    {
        try{
            tiles.push_back( std::make_shared<Tile>( tile_path, tiles.size()) );
        }
        catch(std::exception& e)
        {
            std::cout << "Catched exception: " << e.what() << "\n";
        }
    }
    for( shared_ptr<Tile> tile : tiles)
    {
        
        tile->generateRules(tiles);
        //std::cout << tile.get()->getId;
    }

    

}

vector< shared_ptr<Tile> >& Tileset::getTiles()
{
    return tiles;
}

shared_ptr<Tile> Tileset::getTile(int ID)
{
    if(ID >= 0 && ID < tiles.size())
        return tiles.at(ID);
    else
        return nullptr;
}