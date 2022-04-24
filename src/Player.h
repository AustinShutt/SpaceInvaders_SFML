//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_PLAYER_H
#define INC_28_SPACEINVADERS_PLAYER_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Player : public sf::Sprite{

    sf::Sprite deathAnimation;
    int explodeFrame;

    static sf::Clock clock;
    static float shotCoolDown;
    static bool alive;
public:
    Player();

    static void update();
    static void resetCD();
    static bool shotOffCD();
    static bool isAlive();

    void destroy();
    void respawn();
    sf::Sprite& getDeathAnimation();
    void updateDeathAnimation();
    bool animationComplete();
};


#endif //INC_28_SPACEINVADERS_PLAYER_H
