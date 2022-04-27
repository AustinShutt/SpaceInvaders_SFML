//
// Created by Austin on 4/26/2022.
//

#include "AppManager.h"

std::stack<BaseState*> AppManager::states;
sf::RenderWindow       AppManager::window;

void AppManager::Init() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");    //Creates Window

    sf::View view({VIEW_WIDTH/2.f, VIEW_HEIGHT/2.f},{VIEW_WIDTH, VIEW_HEIGHT} );//Sets window view
    window.setView(view);

    addState(new MainMenu(window));
    //addState(new Game(window));
}

void AppManager::Run() {
    sf::Clock clock;            //SFML clock, resetTimer each cycle and returns time in seconds between calls
    float elapsedTime = 0.f;    //Holds accumulated value of time between cycles

    while (window.isOpen())
    {
        elapsedTime += clock.restart().asSeconds(); //Resets clock, adds time between cycle

        while (elapsedTime >= TIME_STEP)            //Limits update to 60fps
        {
            states.top()->HandleInput();            //Accepts input from user
            states.top()->Update();                 //Updates the scene

            elapsedTime -= TIME_STEP;               //Removes value of time step from time accumulator
        }

        states.top()->Render();                     //Draws the scene to the SFML window
    }
}

void AppManager::addState(BaseState *state) {
    states.push(state);
}

void AppManager::popState() {
    states.pop();
}

