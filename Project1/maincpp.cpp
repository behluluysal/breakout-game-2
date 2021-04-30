#include <SFML/Graphics.hpp>
#include "cerceve.h"
#include "player.h"
#include "brick.h"


float _width = 623.8f; 
float _height = 899.8f;
float cerceveSuresi = 1.0f / 60.0f;

cerceve* c;
player* p;
bool _isGameNotStarted;
bool _isGameFinished;
brick brickList[4][6];


void resetLevel()
{
    c = new cerceve();
    p = new player();
    _isGameNotStarted = true;
    _isGameFinished = false;

    int brick_x;
    int brick_y = 50;
    for (int i = 0; i < 4; i++)
    {
        brick_x = 36;
        for (int j = 0; j < 6; j++) {
            int rand_uret = rand() % 5;
            brickList[i][j] = brick(rand_uret, 0, brick_x, brick_y);
            brick_x += round((232 * 0.3f) + 1);
        }
        brick_y += round((104 * 0.3f) + 1);
    }
}


int main()
{
    sf::Clock saat;
    sf::Time gecenSure;

    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode(_width, _height), "Breakout! If you can haha");

    

    resetLevel();
    

    while (window.isOpen())
    {
        sf::Event event;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            _isGameNotStarted = false;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p->playerMoveR(_isGameNotStarted);
            
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p->playerMoveL(_isGameNotStarted);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            if(_isGameFinished == true)
                resetLevel();
        }


        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        gecenSure += saat.restart();
        if (gecenSure.asSeconds() >= cerceveSuresi)
        {
            window.clear();
            window.draw(p->racket);
            window.draw(p->ball);
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
            for(int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (brickList[i][j].getStatus() != 2)
                        window.draw(brickList[i][j].getSprite());
                }
            }
            window.display();
        }


    }
    return 0;
}