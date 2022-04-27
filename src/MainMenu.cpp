//
// Created by Austin on 4/26/2022.
//

#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &window) :window(window) {
    playButton.setText("PLAY");
    exitButton.setText("EXIT");

    playButton.setPosition({VIEW_WIDTH/2., VIEW_HEIGHT/3.});
    exitButton.setPosition({VIEW_WIDTH/2., VIEW_HEIGHT * 2./ 3.});
}

void MainMenu::HandleInput() {
    //Poll events
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void MainMenu::Update() {
    exitButton.lowlight();
    playButton.lowlight();

    sf::Vector2i coords = sf::Mouse::getPosition(window);
    sf::Vector2f mousePos = window.mapPixelToCoords(coords);

    if(exitButton.getBounds().contains(mousePos))
        exitButton.highlight();
    if(playButton.getBounds().contains(mousePos))
        playButton.highlight();

}

void MainMenu::Render() {
    window.clear();
    window.draw(background);
    window.draw(playButton);
    window.draw(exitButton);
    window.display();
}
