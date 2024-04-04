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
    vector< vector<int> > rules;
    string address; //DEBUG
    int ID;
public:
    Tile() = default;
    Tile(TileInfo info, int ID);
    ~Tile();

    void generateRules(vector<shared_ptr<Tile>>& tiles);
    string getSide(int side);
    int getId();
    cv::Mat& getImage(){return image;}

    std::ostream& operator<<(std::ostream& os);

};
#endif