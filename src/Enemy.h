//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_ENEMY_H
#define INC_28_SPACEINVADERS_ENEMY_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "AssetManager.h"
#include "Definitions.h"

class Enemy : public sf::Sprite {
    static sf::Clock timer;
    static float elapsedTime;
    static float timeToShoot;
    static float animationTime;

    bool isDestroyed;
    int explodeFrame;

public:
    Enemy(EnemyType enemyType);

    static void update();
    void updateAnimation();
    static bool isOffCD();
    static bool timeToAnimate();
    static void resetAnimate();
    void destroy();
    bool explodeComplete();

};


#endif //INC_28_SPACEINVADERS_ENEMY_H
