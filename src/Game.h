//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_GAME_H
#define INC_28_SPACEINVADERS_GAME_H


#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Player.h"
#include "Enemy.h"

class Game{
    sf::RenderWindow   window;
    Player             player;
    std::vector<Enemy> enemies;
public:
    Game();
    void Run();

private:
    void HandleInput();
    void Update();
    void Render();
};




#endif //INC_28_SPACEINVADERS_GAME_H
