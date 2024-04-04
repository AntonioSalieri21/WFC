#ifndef IMAGE_GENERATOR_H
#define IMAGE_GENERATOR_H

#include "grid.h"
#include "string"

using std::string;

class ImageGenerator
{

public:
    static void saveImage(Grid& grid, Tileset& ts, string path);

};

#endif