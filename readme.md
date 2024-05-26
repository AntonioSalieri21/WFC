# Project Wave Function Collapse procedure texture generation

This program generates new textures from small samples (Tiles), or from a sample image.\
Read https://github.com/mxgmn/WaveFunctionCollapse for more.

## Terminology
Tile: image with set of rules, which define which tiles are allowed to be neighbours of this one.\
Tileset: set of Tiles.\
Cell: cell which contains possible Tiles. Can be in collapsed and undefined state. In undefined\
    state cell contains more than one possible Tile or none (which means contradiction and error).\
    In collapsed state Cell has only one possible Tile.\
Grid: 2D array of Cells. \
Enthropy: number of possible states of Cell.

## Prerequisites
You will need opencv for image handling, nlohmann json parser for config parsing and QT for GUI.

Ubuntu:
> sudo apt update\
> sudo apt install libopencv-dev\
> sudo apt-get install nlohmann-json-dev
> sudo apt install -y qtcreator qtbase5-dev qt5-qmake cmake


Arch:
> sudo pacman -S opencv
> sudo pacman -S nlohmann-json
> sudo pacman -S qt6
### Installing
> mkdir build \
> cd build\
> cmake ..\
> make -j

### Running

Program is launched from bash, but runs in GUI.\
Syntax of launching:
* > ./WFCGenerator 

## Features and usage 
This program generates images of arbitrary size based on tileset, created by user, or based on sample image.
Runs in GUI where you can generate image, have its preview and save it.
Config files needs to be created by hand.
For auto generation you should provide config file and sample image.
For manual generation you should provide config file and tile images.
Root folder must contain configs.json, where paths to another configs are provided.

For usage open a program, choose your config, set size of an output image in tiles and generate it.

## Limitations
Despite its usability this algorithm can only meaningfully generate images, which are made of simple pieces.
For more complex structures you should search for another algorithm. 
This implementation features only SimpleTile model.
Also there is no pixel model generation because it fits only for simple small images with contrast colors, which
is not very usefull.
Most often algorithm like this is used for content generation in games, because its very easy to use for generating complex structures from simple tiles, like buildings or rooms.
Also backtracking is not implemented because on practise generation is pretty stable and rarely ends in contradiction.

## Program functioning and structure.

Program starts with reading config.json from drop list. \
From there it can take two paths depending on mode of generation: \
Manual: \
From there it reads tiles: path to their images, their side structure and parameter "rotate", which\
defines if program should automatically create rotated versions of this tile (see config structure below)\

Auto: \
Program reads sample image and divises it into pieces by NxM grid. After that it indexes them and checks for dublicates.\
After creating tiles it writes down which tiles are neighbors to it and saves in rules of this tile. \
Bordering tiles obviously dont have any neighbors beyond the picture, so program fills in the gaps by \
filling the rules from empty side with rules from the opposite side. F.e if tile has no neighbors above \
it will take possible neighbors from under this tile and pass it to a side UP. \
If "rotate" in config is true then creates rotations of those tiles. \

After reading config Tileset initializes and saves shared_ptr to each Tile. shared_ptr is used for\
further accessing to them from another parts of program, such as Grid or Cell.

After initializing Tileset Grid is created. Grid creates Cells which contain vector of shared_ptr to Tiles in Tileset.\
\
After that WFCGenerator class starts generating image by collapsing random Cell in Grid.\
After that cycle is started:
1. Update Grid enthropies.
2. Collapse Cell with least enthropy.
3. Repeat 1-2 untill all cells are collapsed.

Grid is updated by BFS. Each cell, after updating its state, updates all its neighbours, by sending them all possible states of this one.\
When Cell is updating it recieves requirments with all possible Tiles it can be, and if this Cell has Tiles which are not
in those requirments it would delete them. \
By constantly repeating this process all cells are collapsed to satisfy rules of another neighbouring cells.

After collapsing a Grid it is checked for errors (f.e Cell has 0 possible Tiles). If contradiction occured - whole\
generation starts over.

After successfully collapsing Grid it is exported as image.png in folder in which program started. \
After that you can save it where you want, or regenerate image with new random seed. 

## Config structure
Configs.json:
Just has a dictionary of paths to another configs from root directory.
* "config_paths" - dictionary with string of paths

Auto config.json:
Config starts with "type" for program to understand which mode to generate in. If auto mode: "auto", if tile mode "tile"
* path - string path from root directory of config to a sample image
* x - grid width
* y - grid height
* rotate - whether to generate rotated tiles
* threshold - is in range from 0 to 1. If put it simply it allows you to regulate "alikness" of generated image to \
an original one. Higher - more alike, lower - not very alike. In code it determines threshold when program deems two tiles \
similar by texture. If threshold is higher then count of unique tiles is higher and therefore rules for each tile are \more precise, which lowers variability. Is recommended to keep in 0.8 - 0.9, but it depends on sample image, so \
feel free to play with it. \

Tile (manual) config.json:

Config starts with node "tiles" which contain array of nodes, which contain Tiles of Tileset.\
Keys of those nodes are perceived as ID for tiles by a program.\
Those nodes must contain:
* "address" key with address to a Tile image starting from build directory of a program.
* "sides" key with array of 4 elements which contain string description of a Tile image.
Each Tile should be divided into 2D grid, where each cell is assigned some symbol to represent it. 
F.e image of '+' symbol 3x3 pixels should be divided into grid 3x3, where 1 represents white pixel
and 0 - black one. Sides are read in clockwise order UP-RIGHT-DOWN-LEFT: ["010", "010", "010", "010]. Any symbols or string can be used for side representation, symbol-by-pixel is just recommended for non-symmetrical tile support.
* "rotate" key which defines should be rotated by a program (NOTE: it cant diferentiate should tile be rotated two or four
times, which can cause performance issues if done incorrectly, so its recommended to provide rotated tiles beforehand, or\
avoid using Tiles which can be rotated only two times!).
