//
// Created by Austin on 4/26/2022.
//

#include "UFO.h"

sf::Clock   UFO::timer;
float       UFO::accumulator = 0.f;
float       UFO::timeToSpawn;
const float UFO::minTimeBetween   = 6.f;
const int   UFO::endRandomBetween = 15;
EnemyMove   UFO::dir(EnemyMove::LEFT);

UFO::UFO() :alive(true),destroyFrame(0){
    this->setTexture(AssetManager::getSpriteSheet());
    this->setTextureRect(sf::IntRect(48,5,16,7));

    resetTimer();

    if(dir == EnemyMove::LEFT)
        this->setPosition(VIEW_WIDTH, 25 );
    else
        this->setPosition(-getGlobalBounds().width, 25);
}

void UFO::resetTimer() {
    timer.restart();
    accumulator = 0;

    timeToSpawn = minTimeBetween + (std::rand() % endRandomBetween);
}

bool UFO::spawnTime() {

    accumulator+= timer.restart().asSeconds();

    return accumulator > timeToSpawn;
}

bool UFO::isAlive() {

    return alive;
}

void UFO::destroy() {
    alive = false;

    this->setTextureRect(AssetManager::explodeFrames[destroyFrame]);
}

bool UFO::updateDestroyed() {

    if(alive) return false;

    if(++destroyFrame > 3)
    {
        swapDirection();
        return true;
    }

    this->setTextureRect(AssetManager::explodeFrames[destroyFrame]);

    return false;
}

void UFO::swapDirection() {
    if(dir == EnemyMove::LEFT)
        dir = EnemyMove::RIGHT;
    else
        dir = EnemyMove::LEFT;
}

EnemyMove UFO::getDirection() {
    return dir;
}
