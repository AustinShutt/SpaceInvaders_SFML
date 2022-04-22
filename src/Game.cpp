//
// Created by Austin on 4/22/2022.
//

#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");    //Creates Window
    sf::View view({VIEW_WIDTH/2, VIEW_HEIGHT/2},{VIEW_WIDTH, VIEW_HEIGHT} );                //Sets window view
    window.setView(view);

    Barrier a, b, c, d;

    const float OFFSET = 24.f;

    a.setPosition({64 * 1.f - OFFSET, VIEW_HEIGHT*5.f/6.f});
    b.setPosition({64 * 2.f - OFFSET, VIEW_HEIGHT*5.f/6.f});
    c.setPosition({64 * 3.f - OFFSET, VIEW_HEIGHT*5.f/6.f});
    d.setPosition({64 * 4.f - OFFSET, VIEW_HEIGHT*5.f/6.f});

    barriers.push_back(a);
    barriers.push_back(b);
    barriers.push_back(c);
    barriers.push_back(d);
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

        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Space)
            {
                //FIRE
            }
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(-PLAYER_MOVE_SPEED, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(PLAYER_MOVE_SPEED, 0);
}
void Game::Update() {
    player.update();
}

void Game::Render() {
    window.clear();
    window.draw(background);
    window.draw(player);

    for(int i = 0; i < barriers.size(); i++)
        window.draw(barriers[i]);

    window.display();
}