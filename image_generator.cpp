#include "image_generator.h"

void ImageGenerator::saveImage(Grid& grid, Tileset& ts, string path)
{
    //vector<vector<Cell>> cells = grid.getCells();
    int x = grid.getX();
    int y = grid.getY();

    vector<cv::Mat> images;

    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
            images.push_back(  ts.getTile(grid.getCell(j,i)->getTiles().at(0))->getImage() );
    }

    int grid_size = std::sqrt(images.size());
    cv::Mat image(images[0].rows * grid_size, images[0].cols * grid_size, images[0].type());

    for(int i = 0; i < grid_size; i++) {
        for(int j = 0; j < grid_size; j++) {
            cv::Mat roi = image(cv::Rect(j * images[0].cols, i * images[0].rows, images[0].cols, images[0].rows));
            images[i * grid_size + j].copyTo(roi);
        }
    }
    cv::imwrite("image.png", image);
}