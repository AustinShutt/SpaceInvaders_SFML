//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_ENEMY_H
#define INC_28_SPACEINVADERS_ENEMY_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "AssetManager.h"
#include "Definitions.h"

/**
 * @class
 * Encapsulates enemy sprites
 */

class Enemy : public sf::Sprite {
    static sf::Clock timer;
    static float elapsedTime;
    static float timeToShoot;
    static float animationTime;
    static const float ENEMY_ANIMATE_TIME;

    bool isDestroyed;
    int explodeFrame;

public:
    /** Constructor - @param EnemyType - type ONE, TWO, THREE, FOUR */
    Enemy(EnemyType enemyType);
    /** Updates the internal timer of the class*/
    static void update();
    /** Checks if timers have exceeded the cool down to fire weapons*/
    static bool isOffCD();
    /** checks if timers exceed time to animate*/
    static bool timeToAnimate();
    /** resets the animation accumulator*/
    static void resetAnimate();
    /** updates the animation of the sprite*/
    void updateAnimation();
    /** marks the class for destruction by boolean flag*/
    void destroy();
    /** returns true if class is ready for deletion*/
    bool explodeComplete();

};


#endif //INC_28_SPACEINVADERS_ENEMY_H
