#include "WorldHandler.hpp"
#include <algorithm>
#include <fstream>


WorldHandler::WorldHandler(std::size_t height, std::size_t width):
    height(height), width(width) {
        worldCells.reserve(height*width);
        for (std::size_t i = 0; i < height*width; i++){
            worldCells.push_back(WorldHandler::DEAD);
        }
    }


void WorldHandler::insertCells(const CellPattern & pat, std::size_t x, std::size_t y){
    auto outputIt = getSquareIterator(x,y, pat.getWidth());
    auto inputIt = pat.getCells().begin();
    while (inputIt != pat.getCells().end()){
        outputIt.set(*inputIt);
        ++outputIt;
        ++inputIt;
    }
}

void WorldHandler::generateNextGeneration() {
    prevGeneration = worldCells;
    for (std::size_t x = 0; x < width; ++x){
        for (std::size_t y = 0; y < height; ++y) {
            switch (countNeighbours(x,y))
            {
            case 3:
                worldCells[y*width + x] = WorldHandler::ALIVE;
            case 2:
                break;
            default:
                worldCells[y*width + x] = WorldHandler::DEAD;
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

WorldHandler::WHIterator WorldHandler::getSquareIterator(std::size_t x, std::size_t y, std::size_t sqWidth) {
    auto it = worldCells.begin() + y*this->width + x;
    return WorldHandler::WHIterator(it, this->width, sqWidth);
}