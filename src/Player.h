//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_PLAYER_H
#define INC_28_SPACEINVADERS_PLAYER_H

#include <SFML/Graphics.hpp>

class Player : public sf::Sprite {

public:
    Player();

    void update();
};


#endif //INC_28_SPACEINVADERS_PLAYER_H
