//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_BACKGROUND_H
#define INC_28_SPACEINVADERS_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"

/**
 * @class
 * Acts as application background, extends sprite to make
 * it easy to draw and can be easily extended to support different
 * backgrounds.
 */

class Background : public sf::Sprite{
    sf::Texture texture;
public:
    /** Default Constructor */
    Background();
};


#endif //INC_28_SPACEINVADERS_BACKGROUND_H
