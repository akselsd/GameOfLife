#ifndef CELLPATTERN_HPP_INCLUDED
#define CELLPATTERN_HPP_INCLUDED
#include <string>
#include <vector>

class CellPattern
{

public:
    CellPattern(const std::string & filename);

    std::size_t getHeight() const {
        return height;
    };
    std::size_t getWidth() const{
        return width;
    };

    const std::vector<bool> & getCells() const{
        return cells;
    };

    static const CellPattern Gun;

private:
    std::size_t height;
    std::size_t width;

    std::vector<bool> cells;
};
#endif