//
// Created by Austin on 4/22/2022.
//

#include "Projectile.h"


Projectile::Projectile() {
    setTexture(AssetManager::getSpriteSheet());
    setTextureRect(sf::Rect(39,5,1,5));
}
