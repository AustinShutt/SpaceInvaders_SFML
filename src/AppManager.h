//
// Created by Austin on 4/26/2022.
//

#ifndef INC_28_SPACEINVADERS_APPMANAGER_H
#define INC_28_SPACEINVADERS_APPMANAGER_H


#include <SFML/Graphics.hpp>
#include "Game.h"
#include <stack>
#include "MainMenu.h"

class AppManager {
    static std::stack<BaseState*> states;
    static sf::RenderWindow window;
public:
    static void Init();
    static void Run();
    static void addState(BaseState* state);
    static void popState();
};


#endif //INC_28_SPACEINVADERS_APPMANAGER_H
