//
// Created by Austin on 4/22/2022.
//

#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");
}

void Game::Run() {

    sf::Clock clock;            //SFML clock, reset each cycle and returns time in seconds between calls
    float elapsedTime = 0.f;    //Holds accumulated value of time between cycles

    while (window.isOpen())
    {
        elapsedTime += clock.restart().asSeconds(); //Resets clock, adds time between cycle

        while (elapsedTime >= TIME_STEP)            //Limits update to 60fps
        {
            HandleInput();                          //Accepts input from user
            Update();                               //Updates the scene

            elapsedTime -= TIME_STEP;               //Removes value of time step from time accumulator
        }

        Render();                                   //Draws the scene to the SFML window
    }
}

void Game::HandleInput() {

    //Poll events
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}
void Game::Update() {
    //Update Scene
}

void Game::Render() {
    window.clear();
    //Add assets to display here

    window.display();
}