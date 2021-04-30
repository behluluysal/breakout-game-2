#pragma once
#include <SFML/Graphics.hpp>
class player
{
public:
	sf::Sprite racket; //raket width 120,38, height 26,52
	float racketX;
	float racketY;
	sf::Texture racketTextures[5];

	player()
	{
		racketX = 251.71f;
		racketY = 829.38;
		racketTextures[0].loadFromFile("resimler/Bats/bat_black.png", { 22, 176, 463, 102 });
		racketTextures[1].loadFromFile("resimler/Bats/bat_blue.png", { 22, 176, 463, 102 });
		racketTextures[2].loadFromFile("resimler/Bats/bat_orange.png", { 22, 176, 463, 102 });
		racketTextures[3].loadFromFile("resimler/Bats/bat_pink.png", { 22, 176, 463, 102 });
		racketTextures[4].loadFromFile("resimler/Bats/bat_yellow.png", { 22, 176, 463, 102 });
		racket.setTexture(racketTextures[rand() % 5]);
		racket.setScale(0.26f, 0.26f);
		racket.setPosition(racketX, racketY);
	}
};

