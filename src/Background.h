//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_BACKGROUND_H
#define INC_28_SPACEINVADERS_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Background : public sf::Sprite{
    sf::Texture texture;
public:
    Background();
};


#endif //INC_28_SPACEINVADERS_BACKGROUND_H
