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
    float ballArtisX = 1, ballArtisY = 1;
    float lastX = 0;


	gameController(player *pl, brick *bl, cerceve *cl) {
        this->p = pl;
        this->b = bl;
        this->c = cl;
	}

    void ballControl() {
        // Sað duvar kontrol
        if (p->ball.getPosition().x >= 588.4 - (371 * 0.07)) {
            ballArtisX *= -1;
            lastX = p->ball.getPosition().x;
        }
        // Sol duvar kontrol
        if (p->ball.getPosition().x <= 34.6) {
            ballArtisX *= -1;
            lastX = p->ball.getPosition().x;
        }
        // Üst duvar kontrol
        if (p->ball.getPosition().y <= 34.6) {
            ballArtisY *= -1;
            lastX = p->ball.getPosition().x;
        }
        // Alt duvar kontrol
        if (p->ball.getPosition().y >= 865.2 - ((371 * 0.07))) {
            //start = false;
            ballArtisX *= -1;
            //ballArtisY = 0;
            lastX = p->ball.getPosition().x;
        }
        
        
        
        // Raket kontrol
        if (p->ball.getGlobalBounds().intersects(p->racket.getGlobalBounds())) {
            // Raketin Solu
            ballArtisX *= -1;
            lastX = p->ball.getPosition().x;
            ballArtisY *= -1;
        }

        // Brick kontrol
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 6; ++j) {
                if (!b->bricks[i][j].destroyed)
                    if (p->ball.getGlobalBounds().intersects(b->bricks[i][j].item.getGlobalBounds())) {
                        // Brick Solu
                        if (p->ball.getPosition().x <= b->bricks[i][j].item.getPosition().x + (233 * 0.3 / 2)) {
                            // Soldan geliyorsa
                            if (lastX <= p->ball.getPosition().x) {
                                ballArtisX *= -1;
                            }
                        }
                        // Brick Saðý
                        if (p->ball.getPosition().x >= b->bricks[i][j].item.getPosition().x + (233 * 0.3 / 2)) {
                            // Saðdan geliyorsa
                            if (lastX >= p->ball.getPosition().x) {
                                ballArtisX *= -1;
                            }
                        }
                        lastX = p->ball.getPosition().x;
                        if (!b->bricks[i][j].broken) {
                            b->bricks[i][j].item.setTexture(b->brickBrokenTextures[b->bricks[i][j].index]);
                            b->bricks[i][j].broken = true;
                        }
                        else {
                            b->bricks[i][j].destroyed = true;
                        }
                        ballArtisY *= -1;
                        return;
                    }
            }
        }
        
    }
};

