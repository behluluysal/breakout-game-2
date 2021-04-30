#pragma once
#include <SFML/Graphics.hpp>
class player
{
public:
	sf::Sprite racket; //raket width 120,38, height 26,52
	float racketX;
	float racketY;

	sf::Sprite ball;
	float ballX ;
	float ballY ;

	sf::Texture racketTextures[5];
	sf::Texture ballTextures[6];

	player()
	{
		racketX = 251.71f;
		racketY = 829.38;
		racketTextures[0].loadFromFile("resimler/Bats/bat_black.png", { 22, 176, 463, 102 });
		racketTextures[1].loadFromFile("resimler/Bats/bat_blue.png", { 22, 176, 463, 102 });
		racketTextures[2].loadFromFile("resimler/Bats/bat_orange.png", { 22, 176, 463, 102 });
		racketTextures[3].loadFromFile("resimler/Bats/bat_pink.png", { 22, 176, 463, 102 });
		racketTextures[4].loadFromFile("resimler/Bats/bat_yellow.png", { 22, 176, 463, 102 });
		
		ballTextures[0].loadFromFile("resimler/Balls/ball_blue.png", { 68, 68, 371, 371 });
		ballTextures[1].loadFromFile("resimler/Balls/ball_green.png", { 68, 68, 371, 371 });
		ballTextures[2].loadFromFile("resimler/Balls/ball_orange.png", { 68, 68, 371, 371 });
		ballTextures[3].loadFromFile("resimler/Balls/ball_red.png", { 68, 68, 371, 371 });
		ballTextures[4].loadFromFile("resimler/Balls/ball_silver.png", { 68, 68, 371, 371 });
		ballTextures[5].loadFromFile("resimler/Balls/ball_yellow.png", { 68, 68, 371, 371 });
		
		racket.setTexture(racketTextures[rand() % 5]);
		racket.setScale(0.26f, 0.26f);
		racket.setPosition(racketX, racketY);

		ballX = ( ((120.38f- (371 * 0.07f)) /2)+ 251.71f);
		ballY = racketY - (371 * 0.07f);
		ball.setTexture(ballTextures[rand() % 6]);
		ball.setScale(0.07f, 0.07f);
		ball.setPosition(ballX, ballY);
	}

	void playerMoveR(bool x)
	{
		if (racketX < 460) {
			racketX += 5;
			if (x == true)
			{
				ballX += 5;
			}
			ball.setPosition(ballX, ballY);
		}
	}
	void playerMoveL(bool x)
	{
		if (racketX > 40){
			racketX -= 5;
			if (x == true)
			{
				ballX -= 5;
			}
			ball.setPosition(ballX, ballY);
		}
			
	}

	bool ballController() {

	}
};

