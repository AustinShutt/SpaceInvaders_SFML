//
// Created by Austin on 4/26/2022.
//

#ifndef INC_28_SPACEINVADERS_MAINMENU_H
#define INC_28_SPACEINVADERS_MAINMENU_H

#include "BaseState.h"
#include "Background.h"
#include "Button.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
/**
 * @class
 * Acts as the initial menu for the application
 */

class MainMenu : public BaseState{
    sf::RenderWindow&   window;
    Background          background;
    Button              playButton;
    Button              exitButton;

public:
    /** Constructor - takes renderwindow reference */
    MainMenu(sf::RenderWindow& window);
    /** Handles all input from user */
    void HandleInput();
    /** Updates the buttons in the scene to check if moused over */
    void Update();
    /** Renders all assets in the main menu to the screen */
    void Render();

};


#endif //INC_28_SPACEINVADERS_MAINMENU_H
