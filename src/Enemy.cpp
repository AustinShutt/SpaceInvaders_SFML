//
// Created by Austin on 4/22/2022.
//

#include "Enemy.h"

sf::Clock Enemy::timer;
float Enemy::elapsedTime = 0;
float Enemy::timeToShoot = 1.0f;
float Enemy::animationTime = 0.f;

Enemy::Enemy(EnemyType enemyType)
    : isDestroyed(false), explodeFrame(1)
{
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
void Enemy::update() {
    animationTime += timer.getElapsedTime().asSeconds();
    elapsedTime   += timer.restart().asSeconds();
}


void Enemy::updateAnimation() {
    if(isDestroyed)
    {
        this->setTextureRect(AssetManager::explodeFrames[explodeFrame++]);
    }
    else
    {
        sf::IntRect currentRect = this->getTextureRect();
        currentRect.left = (currentRect.left + 16) % 32;
        this->setTextureRect(currentRect);
    }
}

bool Enemy::isOffCD() {

    if(elapsedTime > timeToShoot)
    {
        elapsedTime = 0.f;
        timeToShoot = rand() % 1300;
        timeToShoot = timeToShoot / 1000.f + .3f;
        return true;
    }

    return false;
}

bool Enemy::timeToAnimate() {

    return animationTime > ENEMY_ANIMATE_TIME;
}

void Enemy::resetAnimate() {
    animationTime -= ENEMY_ANIMATE_TIME;
}

bool Enemy::explodeComplete() {
    return explodeFrame > 3;
}

void Enemy::destroy() {
    this->isDestroyed = true;
}
