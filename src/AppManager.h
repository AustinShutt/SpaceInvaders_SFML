//
// Created by Austin on 4/26/2022.
//

#ifndef INC_28_SPACEINVADERS_APPMANAGER_H
#define INC_28_SPACEINVADERS_APPMANAGER_H


#include <SFML/Graphics.hpp>
#include "Game.h"
#include <stack>
#include "MainMenu.h"

/**
 * @class AppManager
 * contains the ability to add and remove BaseStates to the application stack
 */

class AppManager {
    static std::stack<BaseState*> states;
    static sf::RenderWindow window;
public:
    /** initializes render window and adds menu state to stack */
    static void Init();
    /** main game loop */
    static void Run();
    /** adds BaseState* to game stack */
    static void addState(BaseState* state);
    /** removes state from stack and deletes it */
    static void popState();
};


#endif //INC_28_SPACEINVADERS_APPMANAGER_H
