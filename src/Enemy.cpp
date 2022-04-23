//
// Created by Austin on 4/22/2022.
//

#include "Enemy.h"

sf::Clock Enemy::timer;
float Enemy::elapsedTime = 0;
float Enemy::timeToShoot = 1.0f;

Enemy::Enemy(EnemyType enemyType){
    this->setTexture(AssetManager::getSpriteSheet());

    switch(enemyType)
    {
        case EnemyType::ONE:
            this->setTextureRect(sf::Rect(0,0,16,16));
            break;
        case EnemyType::TWO:
            this->setTextureRect(sf::Rect(0,16,16,16));
            break;
        case EnemyType::THREE:
            this->setTextureRect(sf::Rect(0,32,16,16));
            break;
        case EnemyType::FOUR:
            this->setTextureRect(sf::Rect(0,48,16,16));
            break;
    }
}

void Enemy::update() {}

bool Enemy::isOffCD() {

    elapsedTime += timer.restart().asSeconds();

    if(elapsedTime > timeToShoot)
    {
        elapsedTime = 0.f;
        timeToShoot = rand() % 1300;
        timeToShoot = timeToShoot / 1000.f + .3f;
        return true;
    }

    return false;
}
