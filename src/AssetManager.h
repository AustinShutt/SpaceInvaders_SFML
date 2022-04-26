//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_ASSETMANAGER_H
#define INC_28_SPACEINVADERS_ASSETMANAGER_H
#include <SFML/Graphics.hpp>
#include <array>

class AssetManager {
    static sf::Texture spriteSheet;
public:

    static void loadAssets();
    static const sf::Texture& getSpriteSheet();
    static std::array<sf::IntRect, 3> explodeFrames;

};

#endif //INC_28_SPACEINVADERS_ASSETMANAGER_H
