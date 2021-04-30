#include <SFML/Graphics.hpp>
#include "cerceve.h"
float _width = 623.8f; 
float _height = 899.8f;

int main()
{
    cerceve* c = new cerceve();
    sf::RenderWindow window(sf::VideoMode(_width, _height), "ilk Program");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(shape);

        for (int i = 0; i < 26;)
        {
            window.draw(c->verticalWalls[0][i]);
            window.draw(c->verticalWalls[1][i]);
            i++;
        }
        for (int i = 0; i < 16;)
        {
            window.draw(c->horizontalWalls[0][i]);
            window.draw(c->horizontalWalls[1][i]);
            i++;
        }

        window.display();
    }
    return 0;
}