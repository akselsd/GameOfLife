#include <SFML/Graphics.hpp>
#include "GraphicsManager.hpp"

GraphicsManager::GraphicsManager(const WorldHandler & cells, int framerate){
    int h = cells.getHeight();
    int w = cells.getWidth();

    if (h < 300 && w < 300) {
        cellsPrPixel = 2;
    }

    if (h < 100 && w < 100) {
        cellsPrPixel = 8;
    }

    window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(w*cellsPrPixel, h*cellsPrPixel), "Game of Life"
    );

    window->setFramerateLimit(framerate);

    aliveCell = sf::RectangleShape(sf::Vector2f(cellsPrPixel, cellsPrPixel));
    aliveCell.setFillColor(sf::Color::Black);
}

void GraphicsManager::drawCellsToWindow(const WorldHandler & cells) {
    window->clear(sf::Color::White);
    int n = 0;
    for (std::size_t x; x < cells.getWidth(); x++)
    {
        for (std::size_t y = 0; y < cells.getHeight(); y++)
        {
            if (cells.isAlive(x,y)){
                auto s = aliveCell;
                s.setPosition(cellsPrPixel*x, cellsPrPixel*y);
                window->draw(s);
                n++;
            }
        }
        
    }

    window->display();
    
}

bool GraphicsManager::windowClosedEvent() {
    sf::Event event;
     while (window->pollEvent(event))
    {
       if (event.type == sf::Event::Closed)
           window->close();
    }
}