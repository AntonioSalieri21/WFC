#include "tilesetconfig.h"
#include <fstream>
#include <iostream>
#include <map>
#include <functional>
#include <opencv2/core/types.hpp>
#include <opencv2/opencv.hpp>
#include <memory>

using std::vector, std::shared_ptr;

class Pattern 
{

public:
    vector<vector<int>> grid;
    vector<string> sides;
    vector<shared_ptr<Pattern>> neighbors; 

    void generateSides()
    {
        // UP
        for (int i = 0; i < grid[0].size(); ++i) {
            sides[0] += std::to_string(grid[0][i]);
        }

        // RIGHT
        for (int i = 0; i < grid.size(); ++i) {
            sides[1] += std::to_string(grid[i].back());
        }

        // DOWN
        for (int i = 0; i < grid.back().size(); ++i) {
            sides[2] += std::to_string(grid.back()[i]);
        }

        // LEFT
        for (int i = 0; i < grid.size(); ++i) {
            sides[3] += std::to_string(grid[i].front());
        }
    }

    Pattern(vector<vector<int>> grid) : grid(grid)
    {

        generateSides();


    }

    void addNeighbor(std::shared_ptr<Pattern> neighbor) {
        neighbors.push_back(neighbor);
    }
};

double computeSSIM(const cv::Mat& img1, const cv::Mat& img2) //Some image comparing magic here, more robust than hashing 
{
    const double C1 = 6.5025, C2 = 58.5225;
    cv::Mat img1_float, img2_float;
    img1.convertTo(img1_float, CV_32F);
    img2.convertTo(img2_float, CV_32F);

    cv::Mat mu1, mu2;
    cv::GaussianBlur(img1_float, mu1, cv::Size(11, 11), 1.5);
    cv::GaussianBlur(img2_float, mu2, cv::Size(11, 11), 1.5);

    cv::Mat mu1_sq = mu1.mul(mu1);
    cv::Mat mu2_sq = mu2.mul(mu2);
    cv::Mat mu1_mu2 = mu1.mul(mu2);

    cv::Mat sigma1_sq, sigma2_sq, sigma12;

    cv::GaussianBlur(img1_float.mul(img1_float), sigma1_sq, cv::Size(11, 11), 1.5);
    sigma1_sq -= mu1_sq;

    cv::GaussianBlur(img2_float.mul(img2_float), sigma2_sq, cv::Size(11, 11), 1.5);
    sigma2_sq -= mu2_sq;

    cv::GaussianBlur(img1_float.mul(img2_float), sigma12, cv::Size(11, 11), 1.5);
    sigma12 -= mu1_mu2;

    cv::Mat ssim_map;
    ssim_map = ((2 * mu1_mu2 + C1) .mul (2 * sigma12 + C2)) / ((mu1_sq + mu2_sq + C1) .mul (sigma1_sq + sigma2_sq + C2));

    cv::Scalar mssim = cv::mean(ssim_map);

    double ssim = (mssim[0] + mssim[1] + mssim[2]) / 3;

    return ssim;
}

vector<cv::Mat> splitImageIntoGrid(cv::Mat& image, int gridSize) {
    vector<cv::Mat> gridImages;

    // Calculate the size of each sub-image
    int subImageWidth = image.cols / gridSize;
    int subImageHeight = image.rows / gridSize;

    // Loop over the image grid
    for (int y = 0; y < gridSize; ++y) {
        for (int x = 0; x < gridSize; ++x) {
            // Define the ROI for this grid cell
            cv::Rect roi(x * subImageWidth, y * subImageHeight, subImageWidth, subImageHeight);

            // Extract the sub-image and add it to the vector
            cv::Mat subImage = image(roi);
            gridImages.push_back(subImage);
        }
    }

    return gridImages;
}


TilesetConfig::TilesetConfig(string config_path) : path(config_path)
{
    std::ifstream file(config_path + "/config.json");

    if(file.fail()){
        std::cerr << "Failed to open file." << '\n';
        return;
    }

    file >> config;
}

vector<TileInfo> TilesetConfig::getTilesInfo()
{
    vector<TileInfo> res;
    if(config["type"] == "tile") 
    {
        for(const auto& [key, tile] : config["tiles"].items())
        {
            res.push_back(TileInfo { tile["address"], tile["sides"], key, tile["rotate"]});
        }
    }
    else if(config["type"] == "overlap")
    {
        string texPath = path + "/" + (string)config["texture"];
        cv::Mat texture = cv::imread(texPath , cv::IMREAD_COLOR); // Opening texture and extracting info from config
        int gridSize = config["grid_size"];
        int overlapSize = config["overlap_size"];

        std::map<std::string, bool> rule_autofill_options;
        for(json::iterator it = config["rule_autofill_options"].begin(); it != config["rule_autofill_options"].end(); it++) 
        {
            rule_autofill_options[it.key()] = it.value();
        }
        bool repeating = rule_autofill_options["repeating"];
        bool sphere = rule_autofill_options["sphere"];

        vector<cv::Mat> gridImages = splitImageIntoGrid(texture, gridSize); //Creating grid

        double threshold = 1.0;
        std::map<int, cv::Mat> imageMap;
        std::map<int, int> countMap;

        for (int i = 0; i < gridImages.size(); ++i) // Count how much same tile appears in the texture
        {
            // Insert the image into the map
            imageMap[i] = gridImages[i];

            // Compare this image to all the other images
            for (int j = 0; j < i; ++j)
            {
                double ssim = computeSSIM(gridImages[i], gridImages[j]);

                // If the SSIM is above a certain threshold, consider the images to be the same
                if (ssim > threshold)
                {
                    // Increment the count for this image in the count map
                    countMap[j]++;
                    break;
                }
            }

            // If the image was not similar to any other image, add it to the count map
            if (countMap.find(i) == countMap.end())
            {
                countMap[i] = 1;
            }
        }

        vector<vector<int>> grid(gridSize, vector<int>(gridSize));

        int i = 0;
        for (auto& row : grid) {
            for (auto& cell : row) {
                auto it = std::next(imageMap.begin(), i % imageMap.size());
                cell = it->first;
                ++i;
            }
        }

        int N = grid.size(); // Assuming grid is a square
        int X = overlapSize; // Size of the smaller squares

        std::vector<std::shared_ptr<Pattern>> patterns;

        for (int i = 0; i <= N - X; ++i) {
            for (int j = 0; j <= N - X; ++j) {
                std::vector<std::vector<int>> patternGrid;
                for (int k = i; k < i + X; ++k) {
                    std::vector<int> row;
                    for (int l = j; l < j + X; ++l) {
                        row.push_back(grid[k][l]);
                    }
                    patternGrid.push_back(row);
                }
                auto pattern = std::make_shared<Pattern>(patternGrid);
                patterns.push_back(pattern);
            }
        }

        // Add neighbors
        for (int i = 0; i < patterns.size(); ++i) {
            // UP
            if (i >= N) {
                patterns[i]->addNeighbor(patterns[i - N]);
            }
            // RIGHT
            if ((i + 1) % N != 0) {
                patterns[i]->addNeighbor(patterns[i + 1]);
            }
            // DOWN
            if (i < patterns.size() - N) {
                patterns[i]->addNeighbor(patterns[i + N]);
            }
            // LEFT
            if (i % N != 0) {
                patterns[i]->addNeighbor(patterns[i - 1]);
            }
        }

        



        


        // for (const auto& pattern : patterns) {
        //     std::cout << "Pattern:\n";
        //     for (const auto& row : pattern) {
        //         for (const auto& cell : row) {
        //             std::cout << cell << ' ';
        //         }
        //         std::cout << '\n';
        //     }
        //     std::cout << '\n';
        // }




    }

    return res;
}

string TilesetConfig::getGenerationType()
{

    return config["type"];

}
