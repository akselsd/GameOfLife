#include "WorldHandler.hpp"
#include "GraphicsManager.hpp"
#include <iostream>


int main() {
    WorldHandler cells(80, 80);
    cells.insertCells("gun.txt", 20,20);
    
    GraphicsManager gManager(cells, 60);

    while (gManager.isWindowOpen())
    {
        if (gManager.windowClosedEvent()) {
            return 0;
        }
        gManager.drawCellsToWindow(cells);
        cells.generateNextGeneration();
    }
        
}