#pragma once
#include <SFML/Graphics/Sprite.hpp>

struct BrickItem {
	sf::Sprite item;
	int type;
	int status; // 0: Saðlam  1: Kýrýlmýþ  2: Yok Edilmiþ
};


class brick
{
private:
	float scale;
	int width;
	int height;
	int space;
public:
	
	sf::Texture brickTextures[5];
	sf::Texture brickBrokenTextures[5];
	struct BrickItem brickList[4][6];


	brick() {
		scale = 0.35f;
		width = 232;
		height = 104;
		space = 5;
		brickTextures[0].loadFromFile("resimler/Bricks/brick_blue_small.png", { 140, 177, 233, 104 });
		brickTextures[1].loadFromFile("resimler/Bricks/brick_green_small.png", { 140, 177, 233, 104 });
		brickTextures[2].loadFromFile("resimler/Bricks/brick_pink_small.png", { 140, 177, 233, 104 });
		brickTextures[3].loadFromFile("resimler/Bricks/brick_violet_small.png", { 140, 177, 233, 104 });
		brickTextures[4].loadFromFile("resimler/Bricks/brick_yellow_small.png", { 140, 177, 233, 104 });

		brickBrokenTextures[0].loadFromFile("resimler/Bricks/brick_blue_small_cracked.png", { 140, 177, 233, 104 });
		brickBrokenTextures[1].loadFromFile("resimler/Bricks/brick_green_small_cracked.png", { 140, 177, 233, 104 });
		brickBrokenTextures[2].loadFromFile("resimler/Bricks/brick_pink_small_try.png", { 140, 177, 233, 104 });
		brickBrokenTextures[3].loadFromFile("resimler/Bricks/brick_violet_small_cracked.png", { 140, 177, 233, 104 });
		brickBrokenTextures[4].loadFromFile("resimler/Bricks/brick_yellow_small_cracked.png", { 140, 177, 233, 104 });
	
		int brick_x;
		int  brick_y = 80;
		int rand_uret;
		for (int i = 0; i < 4; i++)
		{
			brick_x = 56;
			for (int j = 0; j < 6; j++) {
				rand_uret = rand() % 5;
				brickList[i][j].type = rand_uret;
				brickList[i][j].status = 0;
				brickList[i][j].item.setTexture(brickTextures[rand_uret]);
				brickList[i][j].item.setPosition(brick_x, brick_y);
				brickList[i][j].item.setScale(scale, scale);
				brick_x += round((width * scale) + space);
			}
			brick_y += round((height * scale) + space);
		}
	}
};

