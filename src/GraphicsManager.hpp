#ifndef GRAPHICS_MANAGER_HPP_INCLUDED
#define GRAPHICS_MANAGER_HPP_INCLUDED
#include <memory>
#include <SFML/Graphics.hpp>
#include "WorldHandler.hpp"

class GraphicsManager
{
public:
    GraphicsManager(const WorldHandler & cells, int framerate);

    void drawCellsToWindow(const WorldHandler & cells);

    bool isWindowOpen(){
        return window->isOpen();
    }

    bool windowClosedEvent();

private:
    std::unique_ptr<sf::RenderWindow> window;
    int cellsPrPixel = 1;
    sf::RectangleShape aliveCell;
};

#endif