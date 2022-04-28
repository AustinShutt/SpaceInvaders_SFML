//
// Created by Austin on 4/25/2022.
//

#ifndef INC_28_SPACEINVADERS_TOPDISPLAY_H
#define INC_28_SPACEINVADERS_TOPDISPLAY_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

/**
 * @class shows the information at the top of the screen such as the score
 * and the wave that the user is on
 */
class TopDisplay : public sf::Drawable {

    sf::Text score;
    sf::Text wave;
    int scoreVal;
    int waveVal;

public:
    /** Constructor - Initializes all values */
    TopDisplay();
    /** Adds to score <br/> @param value - value to add to score */
    void addToScore(int value);
    /** Progresses to the next wave */
    void nextWave();
    /** Overwrites draw function to display score and wave text to screen */
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //INC_28_SPACEINVADERS_TOPDISPLAY_H
