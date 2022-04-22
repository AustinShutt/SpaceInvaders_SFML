//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_ENEMY_H
#define INC_28_SPACEINVADERS_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy : public sf::Sprite {
public:
    Enemy();

    void update();
};


#endif //INC_28_SPACEINVADERS_ENEMY_H
