//
// Created by Austin on 4/22/2022.
//

#include "Player.h"

sf::Clock Player::clock;
float Player::shotCoolDown = 0.f;
bool Player::alive = true;

Player::Player()
{
    this->setTexture(AssetManager::getSpriteSheet());
    this->setTextureRect(sf::IntRect(64,0,16,16));
    this->setPosition({VIEW_WIDTH /2.f - 1, VIEW_HEIGHT * 7.f/ 8.f});
    this->setOrigin(9, 0);

    deathAnimation.setTexture(AssetManager::getSpriteSheet());
    deathAnimation.setTextureRect(AssetManager::explodeFrames[1]);
    deathAnimation.setOrigin(9,0);
}

void Player::update() {
    shotCoolDown+= clock.restart().asSeconds();
}

void Player::resetCD() {
    shotCoolDown = 0.f;
}

bool Player::shotOffCD() {
    return shotCoolDown > PLAYER_SHOT_CD;
}

bool Player::isAlive() {
    return alive;
}

sf::Sprite &Player::getDeathAnimation() {
    return deathAnimation;
}

void Player::destroy() {
    alive = false;
    explodeFrame = 1;
    deathAnimation.setPosition(this->getPosition());
}

void Player::updateDeathAnimation() {
    deathAnimation.setTextureRect(AssetManager::explodeFrames[explodeFrame++]);
}

bool Player::animationComplete() {
    return explodeFrame > 3;
}

void Player::respawn() {
    alive = true;
}

