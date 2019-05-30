#ifndef WORLD_HANDLER_HPP_INCLUDED
#define WORLD_HANDLER_HPP_INCLUDED
#include <cstdlib>
#include <vector>
#include <assert.h>
#include <string>
#include "CellPattern.hpp"

class WorldHandler
{
public:
    using value_type = bool;
    using container_type = std::vector<value_type>;
    const value_type DEAD = false;
    const value_type ALIVE = true;

    
    WorldHandler(std::size_t height, std::size_t width);

    void generateNextGeneration();

    void insertCells(const CellPattern & pat, std::size_t x, std::size_t y);


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

    container_type worldCells;
    container_type prevGeneration;

    class WHIterator    
    {
    private:
        container_type::iterator itInstance;
        const std::size_t maxWidth;
        const std::size_t squareWidth;
        int x;

    public:
        WHIterator(container_type::iterator it, std::size_t maxWidth, std::size_t squareWidth):
            itInstance(it), maxWidth(maxWidth), squareWidth(squareWidth), x(0){}
        
        value_type get() const{
            return *itInstance;
        }

        void set(value_type v) const {
            *itInstance = v;
        }
        
        void operator++() {
            operator+(1);
        }
    
        WHIterator operator+(int n){
            assert(x >= 0 && "Negative integer in square iterator");
            
            int offset = n + x;
            std::div_t dv = std::div(offset, (int)squareWidth);
            
            itInstance = itInstance + maxWidth*dv.quot + dv.rem - x;
            x = dv.rem;
        }
    };
    WorldHandler::WHIterator getSquareIterator(std::size_t x, std::size_t y, std::size_t sqWidth);
    
    
};
#endif
