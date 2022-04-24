//
// Created by Austin on 4/22/2022.
//

#include "Player.h"

sf::Clock Player::clock;
float Player::shotCooldown = 0.f;

Player::Player() {
    this->setTexture(AssetManager::getSpriteSheet());
    this->setTextureRect(sf::Rect(64,0,16,16));
    this->setPosition({VIEW_WIDTH /2.f - 1, VIEW_HEIGHT * 7.f/ 8.f});
    this->setOrigin(9, 0);
}

void Player::update() {
    shotCooldown+= clock.restart().asSeconds();
}

void Player::resetCD() {
    shotCooldown = 0.f;
}

bool Player::shotOffCD() {
    return shotCooldown > PLAYER_SHOT_CD;
}
