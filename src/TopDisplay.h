//
// Created by Austin on 4/25/2022.
//

#ifndef INC_28_SPACEINVADERS_TOPDISPLAY_H
#define INC_28_SPACEINVADERS_TOPDISPLAY_H

#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "Definitions.h"

class TopDisplay : public sf::Drawable {

    sf::Text score;
    sf::Text wave;
    int scoreVal;
    int waveVal;

public:
    TopDisplay();
    void addToScore(int value);
    void nextWave();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //INC_28_SPACEINVADERS_TOPDISPLAY_H
