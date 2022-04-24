//
// Created by Austin on 4/24/2022.
//

#ifndef INC_28_SPACEINVADERS_LIFEDISPLAY_H
#define INC_28_SPACEINVADERS_LIFEDISPLAY_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class LifeDisplay : public sf::Drawable{
    std::vector<sf::Sprite> lives;

public:
    LifeDisplay();
    void removeLife();
    void addLife();
    int numLives();

    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //INC_28_SPACEINVADERS_LIFEDISPLAY_H
