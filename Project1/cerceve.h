#pragma once
#include <SFML/Graphics/Sprite.hpp>
class cerceve
{
public:
    sf::Sprite verticalWalls[2][26];
    sf::Sprite horizontalWalls[2][16];
    sf::Texture wallTextures[4];


    cerceve()
    {
        float wallX = 34.6f; //önce sol sað duvar yazýldýðý için alt üst duvarda 0dan deðil 1 kare ileriden yazmalý
        float wallY = 0;
        float wallW = 173 * 0.2f;

        wallTextures[0].loadFromFile("resimler/Walls/brick.png", { 45, 45, 173, 173 });
        wallTextures[1].loadFromFile("resimler/Walls/brick_blue.png", { 45, 45, 173, 173 });
        wallTextures[2].loadFromFile("resimler/Walls/brick_pink_side.png", { 45, 45, 173, 173 });
        wallTextures[3].loadFromFile("resimler/Walls/brick_red.png", { 45, 45, 173, 173 });
        for (int i = 0; i < 26; ++i)
        {
            verticalWalls[0][i].setTexture(wallTextures[rand() % 4]);
            verticalWalls[0][i].setScale({ 0.2f,0.2f });
            verticalWalls[0][i].setPosition(0, wallY);

            verticalWalls[1][i].setTexture(wallTextures[rand() % 4]);
            verticalWalls[1][i].setScale({ 0.2f,0.2f });
            verticalWalls[1][i].setPosition(589.2f, wallY);

            wallY += wallW;
        }
        for (int i = 0; i < 16; ++i)
        {
            horizontalWalls[0][i].setTexture(wallTextures[rand() % 4]);
            horizontalWalls[0][i].setScale({ 0.2f,0.2f });
            horizontalWalls[0][i].setPosition(wallX, 0);

            horizontalWalls[1][i].setTexture(wallTextures[rand() % 4]);
            horizontalWalls[1][i].setScale({ 0.2f,0.2f });
            horizontalWalls[1][i].setPosition(wallX, 865.2f);
            wallX += wallW;
        }
    }

};

