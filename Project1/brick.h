#pragma once
#include <SFML/Graphics/Sprite.hpp>

sf::Texture brickTextures[5];
sf::Texture brickBrokenTextures[5];

class brick
{

private:

	sf::Sprite sprite;

protected:


public:

	int type;
	int status; // 0: Sağlam  1: Kırılmış  2: Yok edilmiş



	brick() {
		type = 0;
		status = 0;
	}

	brick(int type, int status, int x, int y) {
		this->type = type;
		this->status = status;
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
	
		sprite.setTexture(brickTextures[type]);
		sprite.setScale(0.3f, 0.3f);
		sprite.setPosition(x, y);
	}

	void setType(int type) {
		this->type = type;
	}

	int getType() {
		return type;
	}

	void setStatus(int status) {
		this->status = status;
	}

	int getStatus() {
		return status;
	}
	sf::Sprite getSprite() {
		return sprite;
	}
};

