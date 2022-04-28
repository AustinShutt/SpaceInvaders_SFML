//
// Created by Austin on 4/24/2022.
//

#include "LifeDisplay.h"

LifeDisplay::LifeDisplay()
{
    const int START_LIVES = 3;

    for(int i = 0; i < START_LIVES; i++)    //Fills vector with # of starting lives
        addLife();

}

void LifeDisplay::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(int i = 0; i < lives.size(); i++)   //Iterates through sprites
        target.draw(lives[i]);
}

void LifeDisplay::addLife() {
    sf::Sprite life;
    life.setTexture(AssetManager::getSpriteSheet());
    life.setTextureRect(sf::IntRect(64,0,16,16));

    if(lives.empty())                               //Sets first sprite position
       life.setPosition(5, VIEW_HEIGHT-20);
    else                                            //Sets position based on last in vector
       life.setPosition(lives.back().getPosition().x+ 16, lives.back().getPosition().y);

    lives.push_back(life);                          //Adds sprite to vector
}

void LifeDisplay::removeLife() {
    if(lives.empty()) return;

    lives.pop_back();   //Removes the back sprite from the vector
}

int LifeDisplay::numLives() {
    return lives.size();    //Returns the size of the vector as the number of lives in reserve
}


