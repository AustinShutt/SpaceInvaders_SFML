//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_GAME_H
#define INC_28_SPACEINVADERS_GAME_H


#include <SFML/Graphics.hpp>
#include "Definitions.h"

class Game{
    sf::RenderWindow window;

public:
    Game();
    void Run();

private:
    void HandleInput();
    void Update();
    void Render();
};




#endif //INC_28_SPACEINVADERS_GAME_H
