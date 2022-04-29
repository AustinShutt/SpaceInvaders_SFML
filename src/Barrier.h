//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_BARRIER_H
#define INC_28_SPACEINVADERS_BARRIER_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

/**
 * @class
 * encapsulates the barrier that spawns at the beginning of each
 * round that acts as a barrier between the player and enemies
 */

class Barrier : public sf::Sprite{
    int lifeCount;
public:
    /** Default Constructor - sets texture and origin */
    Barrier();
};


#endif //INC_28_SPACEINVADERS_BARRIER_H
