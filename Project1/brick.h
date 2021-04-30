#pragma once
#include <SFML/Graphics/Sprite.hpp>

class brick
{
private:
	sf::Sprite sprite;
	int type;
	int status; // 0: Sağlam  1: Kırılmış  2: Yok edilmiş

public:
	brick() {
		type = 0;
		status = 0;
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
};

