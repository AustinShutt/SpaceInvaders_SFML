//
// Created by Austin on 4/22/2022.
//

#include "Barrier.h"

Barrier::Barrier() : lifeCount(3) {
    this->setTexture(AssetManager::getSpriteSheet());   //Sets texture from asset manager
    this->setTextureRect(sf::IntRect(51,20,26,12));    //Sets initial frame
    this->setOrigin(13,6);                                //sets origin
}
