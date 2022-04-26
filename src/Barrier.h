//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_BARRIER_H
#define INC_28_SPACEINVADERS_BARRIER_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class Barrier : public sf::Sprite{
    static std::array<sf::IntRect, 4> barrierFrames;
    int lifeCount = 3;
public:
    Barrier();
    void hitRegister();
    bool isDestroyed();
};


#endif //INC_28_SPACEINVADERS_BARRIER_H
