//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_GAME_H
#define INC_28_SPACEINVADERS_GAME_H


#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "Player.h"
#include "LifeDisplay.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Barrier.h"
#include "Background.h"
#include "TopDisplay.h"
#include "UFO.h"
#include <queue>
#include <list>

class Game{
    sf::RenderWindow        window;
    Player                  player;
    LifeDisplay             lifeDisplay;
    Background              background;
    std::vector<Enemy>      enemies;
    std::list<Enemy>        destroyed;
    std::list<UFO>          ufos;
    std::vector<Barrier>    barriers;
    std::vector<Projectile> projectiles;
    std::vector<Projectile> enemyProj;

    EnemyMove               movDir;
    EnemyMove               prevDir;
    TopDisplay              topDisplay;

public:
    Game();
    void Run();

private:
    void HandleInput();
    void Update();
    void Render();

    void initializeBarriers();
    void initializeEnemies();

    void shipFire();
    void enemyFire();

    void updateShipAnimations();
    void updatePlayerProjectiles();
    void updateEnemyProjectiles();
    void updateEnemyMovement();
    void updateUFO();
};




#endif //INC_28_SPACEINVADERS_GAME_H
