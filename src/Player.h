//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_PLAYER_H
#define INC_28_SPACEINVADERS_PLAYER_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Player : public sf::Sprite {
    static sf::Clock clock;
    static float shotCooldown;

public:
    Player();

    static void update();
    static void resetCD();
    static bool shotOffCD();
};


#endif //INC_28_SPACEINVADERS_PLAYER_H
