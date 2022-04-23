//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_ENEMY_H
#define INC_28_SPACEINVADERS_ENEMY_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include <cstdlib>
#include "Definitions.h"

class Enemy : public sf::Sprite {
    static sf::Clock timer;
    static float elapsedTime;
    static float timeToShoot;

public:
    Enemy(EnemyType enemyType);

    void update();
    static bool isOffCD();

};


#endif //INC_28_SPACEINVADERS_ENEMY_H
