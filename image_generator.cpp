#include "image_generator.h"

void ImageGenerator::saveImage(Grid& grid, Tileset& ts, string path)
{
    int x = grid.getX();
    int y = grid.getY();

    vector<cv::Mat> images;

    for(int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
            images.push_back(  grid.getCell(j,i)->getTiles().at(0)->getImage() );
    }

    cv::Mat image(images[0].rows * y, images[0].cols * x, images[0].type());

    for(int i = 0; i < y; i++) {
        for(int j = 0; j < x; j++) {
            cv::Mat roi = image(cv::Rect(j * images[0].cols, i * images[0].rows, images[0].cols, images[0].rows));
            images[i * x + j].copyTo(roi);
        }
    }
    cv::imwrite("image.png", image);
}