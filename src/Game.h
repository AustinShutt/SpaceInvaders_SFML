//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_GAME_H
#define INC_28_SPACEINVADERS_GAME_H


#include <SFML/Graphics.hpp>
#include <queue>
#include <list>

#include "BaseState.h"
#include "Definitions.h"
#include "Player.h"
#include "Enemy.h"
#include "Projectile.h"
#include "Barrier.h"
#include "Background.h"
#include "TopDisplay.h"
#include "LifeDisplay.h"
#include "UFO.h"
#include "Button.h"


/**
 * @class
 * Game state that the user will be spending the most time in. Holds
 * most other assets in the application and overwrites the required methods
 * from the base state interface in order to be used in the application stack.
 */

class Game : public BaseState{
    sf::RenderWindow&       window;
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
    Button                  menuButton;
    sf::Text                gameOverText;
    bool                    gameOver;

public:
    /** Constructor - takes in a window reference and initializes play state*/
    Game(sf::RenderWindow& window);
    /** Handles all inputs from the user */
    void HandleInput();
    /** Updates the scene*/
    void Update();
    /** Renders the scene to the window*/
    void Render();

private:
    /** Initializes barriers in game*/
    void initializeBarriers();
    /** Initializes enemies in game*/
    void initializeEnemies();
    /** Sets text for end of game scenario*/
    void initializeText();

    /** Player fires projectile*/
    void shipFire();
    /** Enemies fire projectile*/
    void enemyFire();

    /** Updates animations in the scene*/
    void updateShipAnimations();
    /** Moves player projectiles and checks collisions*/
    void updatePlayerProjectiles();
    /** Moves enemy projectiles and checks collisions*/
    void updateEnemyProjectiles();
    /** Updates the movement of the enemies*/
    void updateEnemyMovement();
    /** Updates the spawn and movement of the UFOs*/
    void updateUFO();
    /** Checks if end of wave has occurred*/
    void updateEndOfWave();
    /** Checks if end of game has occurred*/
    void updateEndGameStatus();
    /** Handles Menu button highlight if moused over*/
    void updateMenuButton();
};

#endif //INC_28_SPACEINVADERS_GAME_H