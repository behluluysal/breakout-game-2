#include <SFML/Graphics.hpp>
#include "cerceve.h"
#include "player.h"
#include "brick.h"
#include "gameController.h"
#include <iostream>

float _width = 623.8f; 
float _height = 899.8f;
float cerceveSuresi = 1.0f / 60.0f;

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

            if (!_isGameNotStarted) {
                p->ballX += g->ballArtisX;
                p->ballY -= g->ballArtisY;
                p->ball.setPosition(p->ballX, p->ballY);
                g->ballControl();
            }

           

            std::cout << "x: "<< p->ballX<<" y: "<<p->ballY<<" artisX: "<<g->ballArtisX<<std::endl;
            
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
        }


    }
    return 0;
}