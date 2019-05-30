#include "WorldHandler.hpp"
#include "GraphicsManager.hpp"
#include "CellPattern.hpp"
#include <iostream>


int main() {
    WorldHandler cells(80, 80);
    cells.insertCells(CellPattern::Gun, 20,20);
    
    GraphicsManager gManager(cells, 30);

    while (gManager.isWindowOpen())
    {
        if (gManager.windowClosedEvent()) {
            return 0;
        }
        gManager.drawCellsToWindow(cells);
        cells.generateNextGeneration();
    }        
}