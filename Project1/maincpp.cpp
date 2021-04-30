#include <SFML/Graphics.hpp>
#include "cerceve.h"
#include "player.h"


float _width = 623.8f; 
float _height = 899.8f;
float cerceveSuresi = 1.0f / 60.0f;


int main()
{
    sf::Clock saat;
    sf::Time gecenSure;

    srand(time(0));
    cerceve* c = new cerceve();
    player* p = new player();
    sf::RenderWindow window(sf::VideoMode(_width, _height), "ilk Program");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen())
    {
        sf::Event event;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            //start = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            if (p->racketX < 460)
                p->racketX += 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if (p->racketX > 40)
                p->racketX -= 1;
        }

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        gecenSure += saat.restart();
        

        if (gecenSure.asSeconds() >= cerceveSuresi)
        {
            p->racket.setPosition(p->racketX, p->racketY);


            window.clear();
            window.draw(shape);
            window.draw(p->racket);
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

        
    }
    return 0;
}