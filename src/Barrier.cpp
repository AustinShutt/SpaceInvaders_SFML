//
// Created by Austin on 4/22/2022.
//

#include "Barrier.h"

Barrier::Barrier() {
    this->setTexture(AssetManager::getSpriteSheet());
    this->setTextureRect(sf::Rect(48,16,32,16));
    this->setOrigin(16,8);
}
