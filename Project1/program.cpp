#include <SFML/Graphics.hpp>
#include "cerceve.h"
#include "player.h"
#include "brick.h"
#include "gameController.h"
#include <iostream>

float frameWidth = 623.8f; 
float frameHeight = 899.8f;
float FPS = 1.0f / 60.0f;

cerceve* c;
player* p;
brick* b;
gameController* g;
bool _isGameNotStarted;
bool _isGameFinished;
brick brickList[4][6];

void resetLevel()
{
    c = new cerceve();
    p = new player();
    b = new brick();
    g = new gameController(p,b,c);
    _isGameNotStarted = true;
    _isGameFinished = false;

    int brick_x;
    int brick_y = 50;
    
}


int main()
{
    sf::Clock clk;
    sf::Time passedTime;

    srand(time(0));
    
    sf::RenderWindow window(sf::VideoMode(frameWidth, frameHeight), "Breakout! If you can haha");

    resetLevel();
    
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
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
                if (_isGameFinished == true)
                    resetLevel();
            }
        }



        passedTime += clk.restart();
        if (passedTime.asSeconds() >= FPS)
        {
            p->raket.setPosition(p->raket_x, p->raket_y);

            if (!_isGameNotStarted) {
                p->ball_x += g->ball_incX;
                p->ball_y -= g->ball_incY;
                p->ball.setPosition(p->ball_x, p->ball_y);
                g->ballControl(&_isGameFinished);
            }

            window.clear();
            window.draw(p->raket);
            window.draw(p->ball);

            std::cout << p->raket_x << std::endl;
            //std::cout << "x: "<< p->ball_x<<" y: "<<p->ball_y<<" artisX: "<<g->ball_incX<<std::endl;
            
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
                for (int j = 0; j < 6; j++)
                {
                    if (b->brickList[i][j].status != 2)
                        window.draw(b->brickList[i][j].item);
                }
            }
            window.display();
            passedTime -= passedTime;
        }


    }
    return 0;
}