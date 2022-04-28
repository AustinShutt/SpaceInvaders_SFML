//
// Created by Austin on 4/24/2022.
//

#ifndef INC_28_SPACEINVADERS_LIFEDISPLAY_H
#define INC_28_SPACEINVADERS_LIFEDISPLAY_H

#include <SFML/Graphics.hpp>
#include "Player.h"

/**
 * @class
 * Shows the lives in the bottom left corner
 */

class LifeDisplay : public sf::Drawable{
    std::vector<sf::Sprite> lives;

public:
    /** Default Constructor */
    LifeDisplay();
    /** Removes a life from display */
    void removeLife();
    /** Adds a life to the display */
    void addLife();
    /** Returns the # of lives in reserve */
    int numLives();
    /** Overwrites draw function to draw all sprites */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //INC_28_SPACEINVADERS_LIFEDISPLAY_H
