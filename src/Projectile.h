//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_PROJECTILE_H
#define INC_28_SPACEINVADERS_PROJECTILE_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"

/**
 * @class projectile used by both user and enemies to fire
 * at one another in an attempt to destroy each other.
 */
class Projectile : public sf::Sprite{
public:
    Projectile();
};


#endif //INC_28_SPACEINVADERS_PROJECTILE_H
