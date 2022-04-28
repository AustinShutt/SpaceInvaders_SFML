//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_ASSETMANAGER_H
#define INC_28_SPACEINVADERS_ASSETMANAGER_H
#include <SFML/Graphics.hpp>
#include <array>

/**
 * @class AssetManager
 * contains the assets and fonts in a convenient place for
 * the application to access
 */
class AssetManager {
    static sf::Texture spriteSheet;
    static sf::Font    font;
public:
    /** loads the assets in to memory from files */
    static void loadAssets();
    /** returns the sprite sheet */
    static const sf::Texture& getSpriteSheet();
    /** returns the font */
    static const sf::Font& getFont();
    /** returns the explode frames */
    static std::array<sf::IntRect, 3> explodeFrames;

};

#endif //INC_28_SPACEINVADERS_ASSETMANAGER_H
