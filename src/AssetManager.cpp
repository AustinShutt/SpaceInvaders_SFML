//
// Created by Austin on 4/22/2022.
//

#include "AssetManager.h"

sf::Texture AssetManager::spriteSheet;

std::array<sf::IntRect, 3> AssetManager::explodeFrames{
    sf::IntRect(32,32,16,16),
    sf::IntRect(32,48,16,16),
    sf::IntRect(32,64,16,16)
};


void AssetManager::loadAssets() {
    spriteSheet.loadFromFile("../assets/si_sheet.png");
}

sf::Texture const& AssetManager::getSpriteSheet() {
    return spriteSheet;
}
