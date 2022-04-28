//
// Created by Austin on 4/26/2022.
//

#ifndef INC_28_SPACEINVADERS_UFO_H
#define INC_28_SPACEINVADERS_UFO_H

#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "AssetManager.h"
#include "Definitions.h"

/**
 * @class UFO that moves across the top of the screen
 */
class UFO : public sf::Sprite {
    static sf::Clock timer;
    static float accumulator;
    static float timeToSpawn;
    static const float minTimeBetween;
    static const int endRandomBetween;
    static EnemyMove dir;

    bool alive;
    int destroyFrame;
public:
    /** Constructor - intializes all values */
    UFO();

    /** returns if the UFO is alive */
    bool isAlive();
    /** sets the flag alive to false */
    void destroy();
    /** update the animation of the UFO when destroyed */
    bool updateDestroyed();

    /** Resets the internal accumulator timer */
    static void resetTimer();
    /** Returns whether the spawn timer has been surpassed */
    static bool spawnTime();
    /** Swaps the direction of the UFO's travel */
    static void swapDirection();
    /** Returns the direction of the UFO's travel */
    static EnemyMove getDirection();
};


#endif //INC_28_SPACEINVADERS_UFO_H
