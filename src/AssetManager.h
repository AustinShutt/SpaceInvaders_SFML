//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_ASSETMANAGER_H
#define INC_28_SPACEINVADERS_ASSETMANAGER_H
#include <SFML/Graphics.hpp>

class AssetManager {
    static sf::Texture spriteSheet;
public:

    static void loadAssets();
    static const sf::Texture& getSpriteSheet();
};

#endif //INC_28_SPACEINVADERS_ASSETMANAGER_H
