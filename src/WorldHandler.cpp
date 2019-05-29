#include "WorldHandler.hpp"
#include <algorithm>
#include <fstream>


WorldHandler::WorldHandler(std::size_t height, std::size_t width):
    height(height), width(width) {
        worldCells.reserve(height*width);
        for (std::size_t i = 0; i < height*width; i++){
            worldCells.push_back(false);
        }
    }


void WorldHandler::insertCells(const std::string & filename, std::size_t x, std::size_t y){
    std::ifstream fs;
    try
    {
        fs.open(filename, std::fstream::in);
    }
    catch(const std::exception& e)
    {
        assert(false && e.what());
    }

    auto it = worldCells.begin() + y*width + x;

    std::string row;
    while(getline(fs, row)){
        auto prevLineIt = it;

        std::for_each(row.begin(), row.end(), 
            [&](const char & s) {
                if (s == 'O' || s == '0'){
                    *it = true;
                }
                else if (s == '.'){
                    *it = false;
                }
                else {
                    assert(false && "Unknown character in cell file");
                }
                ++it;
            });
        it = prevLineIt + width;
    }
}

void WorldHandler::generateNextGeneration() {
    prevGeneration = worldCells;
    for (std::size_t x = 0; x < width; ++x){
        for (std::size_t y = 0; y < height; ++y) {
            switch (countNeighbours(x,y))
            {
            case 3:
                worldCells[y*width + x] = true;
            case 2:
                break;
            default:
                worldCells[y*width + x] = false;
                break;
            }     
        }
    }
}

int WorldHandler::countNeighbours(std::size_t x, std::size_t y) const {
    int n = 0;

    for (std::size_t _x = std::max(0, (int)x - 1); _x < std::min(width, x + 2); _x++){
        for (std::size_t _y = std::max(0, (int)y - 1); _y < std::min(height, y + 2); _y++){
            if (x == _x && y == _y) {
                continue;
            }

            if (prevGeneration[width*_y + _x]){
                ++n;
            }
        }
    }
    return n;
    
}