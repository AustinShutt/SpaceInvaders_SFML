//
// Created by Austin on 4/22/2022.
//

#include "Projectile.h"


Projectile::Projectile() {
    this->setTexture(AssetManager::getSpriteSheet());
    this->setTextureRect(sf::Rect(39,5,1,5));
}
