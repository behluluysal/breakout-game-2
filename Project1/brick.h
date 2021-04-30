#pragma once
#include <SFML/Graphics/Sprite.hpp>



class brick
{
public:
	struct Brick {
		sf::Sprite item;
		int index;
		bool broken;
		bool destroyed;
	};
	sf::Texture brickTextures[5];
	sf::Texture brickBrokenTextures[5];
	struct Brick bricks[4][6];


	brick() {
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
	
		int brickX = 56, brickY = 80;
		for (int i = 0; i < 4; ++i)
		{
			brickX = 56;
			for (int j = 0; j < 6; ++j) {
				int random = rand() % 5;
				bricks[i][j].index = random;
				bricks[i][j].broken = false;
				bricks[i][j].destroyed = false;
				bricks[i][j].item.setTexture(brickTextures[random]);
				bricks[i][j].item.setScale(0.35f, 0.35f);
				bricks[i][j].item.setPosition(brickX, brickY);
				brickX += round((232 * 0.35f) + 5);
			}
			brickY += round((104 * 0.35f) + 5);
		}
	}
};

