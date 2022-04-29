//
// Created by Austin on 4/22/2022.
//

#include "Barrier.h"

Barrier::Barrier() : lifeCount(3) {
    setTexture(AssetManager::getSpriteSheet());   //Sets texture from asset manager
    setTextureRect(sf::IntRect(51,20,26,12));    //Sets initial frame
    setOrigin(13,6);                                //sets origin
}
