//
// Created by Austin on 4/22/2022.
//

#include "AssetManager.h"

sf::Texture AssetManager::spriteSheet;

void AssetManager::loadAssets() {
    spriteSheet.loadFromFile("../assets/si_sheet.png");
}

sf::Texture const& AssetManager::getSpriteSheet() {
    return spriteSheet;
}
