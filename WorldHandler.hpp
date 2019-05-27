#ifndef WORLD_HANDLER_HPP_INCLUDED
#define WORLD_HANDLER_HPP_INCLUDED
#include <cstdlib>
#include <vector>
#include <assert.h>
#include <string>

class WorldHandler
{
public:
    WorldHandler(std::size_t height, std::size_t width);

    void generateNextGeneration();

    void insertCells(const std::string & filename, std::size_t x, std::size_t y);


    bool isAlive(std::size_t x, std::size_t y) const {
        assert(x >= 0);
        assert(x < width);
        assert(y >= 0);
        assert(y < height);

        return worldCells[y*width + x];
    }

    std::size_t getHeight() const {
        return height;
    }

    std::size_t getWidth() const {
        return width;
    }

private:

    int countNeighbours(std::size_t x, std::size_t y) const;

    std::size_t height;
    std::size_t width;

    std::vector<bool> worldCells;
    std::vector<bool> prevGeneration;
    
};

#endif