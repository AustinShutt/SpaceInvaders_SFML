//
// Created by Austin on 4/22/2022.
//

#include "Barrier.h"

//Initialize static variable
std::array<sf::IntRect , 4> Barrier::barrierFrames{
        sf::IntRect(51,68,26,12),
        sf::IntRect(51,52,26,12),
        sf::IntRect(51,36,26,12),
        sf::IntRect(51,20,26,12)
};

Barrier::Barrier() : lifeCount(3) {
    this->setTexture(AssetManager::getSpriteSheet());   //Sets texture from asset manager
    this->setTextureRect(barrierFrames[lifeCount]);    //Sets initial frame
    this->setOrigin(13,6);                                //sets origin
}

void Barrier::hitRegister() {
    lifeCount--;                    //Remove from life counter, goes backwards in array

    if(lifeCount >= 0)              //Ensure >= 0 value prior to array index call
        this->setTextureRect(barrierFrames[lifeCount]);
}

bool Barrier::isDestroyed() {
    return lifeCount < 0;
}

