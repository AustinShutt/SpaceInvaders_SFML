//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_PLAYER_H
#define INC_28_SPACEINVADERS_PLAYER_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

/**
 * @class
 * User class that controls the ship sprite at the bottom of the screen and is able to fire projectiles.
 */


class Player : public sf::Sprite{

    sf::Sprite          deathAnimation;
    int                 explodeFrame;

    static sf::Clock    clock;
    static float        shotCoolDown;
    static bool         alive;
    static const float  PLAYER_SHOT_CD;
public:
    /** Default Constructor */
    Player();
    /** Resets the internal timer */
    static void update();
    /** Resets the internal accumulator value for shot cool down */
    static void resetCD();
    /** Checks if shoot timer is off cooldown */
    static bool shotOffCD();
    /** Returns if user ship is currently alive */
    static bool isAlive();

    /** Sets status of ship to destroyed */
    void destroy();
    /** Respawns the user player ship */
    void respawn();
    /** Returns the death animation sprite */
    sf::Sprite& getDeathAnimation();
    /** Updates the player death animation */
    void updateDeathAnimation();
    /** Returns if the animation is complete */
    bool animationComplete();
};


#endif //INC_28_SPACEINVADERS_PLAYER_H
