#ifndef IMAGE_GENERATOR_H
#define IMAGE_GENERATOR_H

#define MAX_IMAGE_SIZE_X 3840
#define MAX_IMAGE_SIZE_Y 3840

#include "grid.h"
#include "string"

using std::string;

class ImageGenerator
{

public:
    static void saveImage(Grid& grid, Tileset& ts, string path);

};

#endif