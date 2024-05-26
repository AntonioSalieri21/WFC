#ifndef TILE_H
#define TILE_H

#include <string>
#include <opencv2/opencv.hpp>
#include <vector>
#include "tileinfo.h"
#include <memory>

using std::string, std::vector, std::shared_ptr;

class Tile
{
    cv::Mat image;
    vector<string> sides;
    vector< vector<string> > rules;
    string address; 
    string ID;
public:
    Tile(TileInfo info);
    ~Tile();

    void generateRules(vector<shared_ptr<Tile>>& tiles);
    string getSide(int side);
    string getId();
    cv::Mat& getImage(){return image;}
    vector<vector<string>>& getRules(){return rules;}

    std::ostream& operator<<(std::ostream& os);

};
#endif