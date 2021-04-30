#pragma once
#include "player.h"
#include "brick.h"
#include "cerceve.h"


class gameController
{
public:
    player *p;
    brick *b;
    cerceve* c;
    float ball_incX = 3, ball_incY = 3;
    float lastX = 0;


	gameController(player *pl, brick *bl, cerceve *cl) {
        this->p = pl;
        this->b = bl;
        this->c = cl;
	}

    void ballControl(bool *_isGameFinished) {
        int r = rand() % 2;
        if (p->ball.getPosition().x >= 588.4 - (371 * 0.07)) {
            ball_incX *= -1;
            lastX = p->ball.getPosition().x;
        }
        if (p->ball.getPosition().x <= 34.6) {
            ball_incX *= -1;
            lastX = p->ball.getPosition().x;
        }
        if (p->ball.getPosition().y <= 34.6) {
            ball_incY *= -1;
            lastX = p->ball.getPosition().x;
        }
        if (p->ball.getPosition().y >= 865.2 - ((371 * 0.07))) {
            *_isGameFinished = true;
            ball_incX = 0;
            ball_incY = 0;
            lastX = p->ball.getPosition().x;
        }
        
        if (p->ball.getGlobalBounds().intersects(p->raket.getGlobalBounds())) {
            if (r == 0) {
                ball_incX *= -1;
            }
            lastX = p->ball.getPosition().x;
            ball_incY *= -1;
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (b->brickList[i][j].status != 2)
                    if (p->ball.getGlobalBounds().intersects(b->brickList[i][j].item.getGlobalBounds())) {
                        if (p->ball.getPosition().x <= b->brickList[i][j].item.getPosition().x + (233 * 0.35 / 2)) {
                            if (lastX <= p->ball.getPosition().x) {
                                ball_incX *= -1;
                            }
                        }
                        if (p->ball.getPosition().x >= b->brickList[i][j].item.getPosition().x + (233 * 0.35 / 2)) {
                            if (lastX >= p->ball.getPosition().x) {
                                ball_incX *= -1;
                            }
                        }
                        lastX = p->ball.getPosition().x;
                        if (b->brickList[i][j].status != 1) {
                            b->brickList[i][j].item.setTexture(b->textures_brick_broken[b->brickList[i][j].type]);
                            b->brickList[i][j].status = 1;
                        }
                        else {
                            b->brickList[i][j].status = 2;
                        }
                        ball_incY *= -1;
                        return;
                    }
            }
        }
        
    }
};

