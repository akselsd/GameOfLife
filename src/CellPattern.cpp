#include "CellPattern.hpp"
#include <fstream>
#include <assert.h>
#include <algorithm>

const CellPattern CellPattern::Gun("patterns/gun.pattern");


CellPattern::CellPattern(const std::string & filename){
    std::ifstream fs;
    try
    {
        fs.open(filename, std::fstream::in);
    }
    catch(const std::exception& e)
    {
        assert(false && e.what());
    }

    bool firstRow = true;
    std::string row;
    while(getline(fs, row)){
        if (firstRow){
            width = row.size();
            firstRow = false;
        }
        else{
            assert(width == row.size());
        }
        

        std::for_each(row.begin(), row.end(), 
            [&](const char & s) {
                if (s == 'O' || s == '0'){
                    cells.push_back(true);
                }
                else if (s == '.'){
                    cells.push_back(false);
                }
                else {
                    assert(false && "Unknown character in cell file");
                }
            });
    }
    height = cells.size()/width;
}


