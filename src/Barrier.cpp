//
// Created by Austin on 4/22/2022.
//

#include "Barrier.h"

std::array<sf::IntRect , 4> Barrier::barrierFrames{
        sf::IntRect(51,68,26,12),
        sf::IntRect(51,52,26,12),
        sf::IntRect(51,36,26,12),
        sf::IntRect(51,20,26,12)
};

Barrier::Barrier() {
    this->setTexture(AssetManager::getSpriteSheet());
    this->setTextureRect(barrierFrames[lifeCount]);
    this->setOrigin(13,6);
}

void Barrier::hitRegister() {
    lifeCount--;

    if(lifeCount >= 0)
        this->setTextureRect(barrierFrames[lifeCount]);
}

bool Barrier::isDestroyed() {
    return lifeCount < 0;
}

