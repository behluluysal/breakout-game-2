#pragma once
#include <SFML/Graphics.hpp>
class player
{
public:
	sf::Sprite raket;
	float raket_x;
	float raket_y;

	sf::Sprite ball;
	float ball_x ;
	float ball_y ;

	sf::Texture textures_raket[5];
	sf::Texture textures_ball[6];

	player()
	{
		raket_x = 251.71f;
		raket_y = 829.38;
		textures_raket[0].loadFromFile("resimler/Bats/bat_black.png", { 22, 176, 463, 102 });
		textures_raket[1].loadFromFile("resimler/Bats/bat_blue.png", { 22, 176, 463, 102 });
		textures_raket[2].loadFromFile("resimler/Bats/bat_orange.png", { 22, 176, 463, 102 });
		textures_raket[3].loadFromFile("resimler/Bats/bat_pink.png", { 22, 176, 463, 102 });
		textures_raket[4].loadFromFile("resimler/Bats/bat_yellow.png", { 22, 176, 463, 102 });
		
		textures_ball[0].loadFromFile("resimler/Balls/ball_blue.png", { 68, 68, 371, 371 });
		textures_ball[1].loadFromFile("resimler/Balls/ball_green.png", { 68, 68, 371, 371 });
		textures_ball[2].loadFromFile("resimler/Balls/ball_orange.png", { 68, 68, 371, 371 });
		textures_ball[3].loadFromFile("resimler/Balls/ball_red.png", { 68, 68, 371, 371 });
		textures_ball[4].loadFromFile("resimler/Balls/ball_silver.png", { 68, 68, 371, 371 });
		textures_ball[5].loadFromFile("resimler/Balls/ball_yellow.png", { 68, 68, 371, 371 });
		
		raket.setTexture(textures_raket[rand() % 5]);
		raket.setScale(0.26f, 0.26f);
		raket.setPosition(raket_x, raket_y);

		ball_x = ( ((120.38f- (371 * 0.07f)) /2)+ 251.71f);
		ball_y = raket_y - (371 * 0.07f);
		ball.setTexture(textures_ball[rand() % 6]);
		ball.setScale(0.07f, 0.07f);
		ball.setPosition(ball_x, ball_y);
	}

	void playerMoveR(bool x)
	{
		if (raket_x < 460) {
			raket_x += 5;
			if (x == true)
			{
				ball_x += 5;
			}
			ball.setPosition(ball_x, ball_y);
		}
	}
	void playerMoveL(bool x)
	{
		if (raket_x > 40){
			raket_x -= 5;
			if (x == true)
			{
				ball_x -= 5;
			}
			ball.setPosition(ball_x, ball_y);
		}
			
	}

	bool ballController() {

	}
};

