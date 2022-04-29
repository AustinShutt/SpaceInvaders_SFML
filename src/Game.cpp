//
// Created by Austin on 4/22/2022.
//

#include "Game.h"
#include "AppManager.h"

Game::Game(sf::RenderWindow& window) : window(window), gameOver(false) {

    initializeText();
    initializeBarriers();
    initializeEnemies();
    player.respawn();
}

void Game::HandleInput() {
    //Poll events
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if(!gameOver && event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Space)                   //Fires weapon based on spacebar event from user
                shipFire();
        }

        if(gameOver && event.type == sf::Event::MouseButtonPressed)
        {
            if(event.mouseButton.button == sf::Mouse::Left)
            {
                AppManager::popState();                                 //pops state from assetmanager and returns app to the main menu
                return;                                                 //exits function early because remaining objects in this scope have been deleted
            }
        }
    }

    const float PLAYER_MOVE_SPEED = 1.0f;

    //Uses realtime key feedback to move ship left/right. Offers smoother experience for user.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        if(player.getPosition().x > player.getGlobalBounds().width/2)
            player.move(-PLAYER_MOVE_SPEED, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        if(player.getPosition().x < VIEW_WIDTH - player.getGlobalBounds().width/2)
            player.move(PLAYER_MOVE_SPEED, 0);
}
void Game::Update() {

    if(!gameOver)
    {
        Player::update();
        Enemy::update();
        enemyFire();
        updateEnemyProjectiles();
        updatePlayerProjectiles();
        updateEnemyMovement();
        updateUFO();
        updateShipAnimations();
        updateEndGameStatus();
        updateEndOfWave();
    }
    else
    {
        updateMenuButton();
    }
}
void Game::Render() {
    window.clear();
    window.draw(background);

    if(!gameOver)
    {
        if(Player::isAlive())
            window.draw(player);
        else
            window.draw(player.getDeathAnimation());

        for(std::list<UFO>::iterator   itr = ufos.begin(); itr != ufos.end();           ++itr) window.draw(*itr);
        for(std::list<Enemy>::iterator itr = destroyed.begin(); itr != destroyed.end(); ++itr) window.draw(*itr);
        for(int i = 0; i < barriers.size();    i++) window.draw(barriers[i]);
        for(int i = 0; i < enemies.size();     i++) window.draw(enemies[i]);
        for(int i = 0; i < projectiles.size(); i++) window.draw(projectiles[i]);
        for(int i = 0; i < enemyProj.size();   i++) window.draw(enemyProj[i]);
    }
    else
    {
        window.draw(menuButton);
        window.draw(gameOverText);
    }
    window.draw(lifeDisplay);
    window.draw(topDisplay);
    window.display();
}

void Game::initializeBarriers() {
    Barrier a, b, c, d;

    const float OFFSET = 24.f;

    a.setPosition({64 * 1.f - OFFSET, VIEW_HEIGHT*5.f/6.f});
    b.setPosition({64 * 2.f - OFFSET, VIEW_HEIGHT*5.f/6.f});
    c.setPosition({64 * 3.f - OFFSET, VIEW_HEIGHT*5.f/6.f});
    d.setPosition({64 * 4.f - OFFSET, VIEW_HEIGHT*5.f/6.f});

    barriers.clear();
    barriers.push_back(a);
    barriers.push_back(b);
    barriers.push_back(c);
    barriers.push_back(d);
}

void Game::initializeEnemies() {

    movDir = EnemyMove::RIGHT;
    int num = VIEW_WIDTH / 16;
    unsigned int padding = 5;
    unsigned int yOffset = 50;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            Enemy temp(static_cast<EnemyType>(i/2));

            temp.setPosition(num * j + padding, i * num + padding + yOffset);
            enemies.push_back(temp);
        }
    }
}

void Game::initializeText() {
    gameOverText.setFont(AssetManager::getFont());
    gameOverText.setString("GAME OVER");
    gameOverText.setPosition(VIEW_WIDTH / 2, VIEW_HEIGHT / 3);
    gameOverText.setCharacterSize(20);
    gameOverText.setOrigin(gameOverText.getGlobalBounds().width/2, 0);


    menuButton.setText("Menu");
    menuButton.setPosition({VIEW_WIDTH / 2, VIEW_HEIGHT / 2});
}

void Game::shipFire() {

    if(!Player::shotOffCD()) return;

    Projectile proj;
    proj.setPosition(player.getPosition());
    projectiles.push_back(proj);

    Player::resetCD();
}

void Game::enemyFire() {
    if(Enemy::isOffCD() && !enemies.empty())
    {
        int enemyPos = rand() % enemies.size();
        Projectile projectile;
        projectile.setPosition(enemies[enemyPos].getPosition());
        enemyProj.push_back((projectile));
    }
}


void Game::updateShipAnimations() {

    if(Enemy::timeToAnimate())
    {
        //Iterates through alive enemies and updates their animation
        for(int i = 0; i < enemies.size(); i++)
            enemies[i].updateAnimation();

        //Iterates through the list of destroyed enemies and updates their animation
        for(std::list<Enemy>::iterator itr = destroyed.begin(); itr != destroyed.end(); ++itr)
            itr->updateAnimation();

        //Iterates through the list of destroyed enemies and updates their animation
        for(std::list<UFO>::iterator itr = ufos.begin(); itr != ufos.end(); ++itr){
            if(itr->updateDestroyed())
            {
                ufos.clear();
                break;
            }
        }

        //Resets the clock value
        Enemy::resetAnimate();

        //Checks if the oldest destroyed enemy has finished animation, pops if complete
        if(!destroyed.empty() && destroyed.front().explodeComplete())
            destroyed.pop_front();

        //If player is dead, update death animation
        if(!Player::isAlive())
        {
            player.updateDeathAnimation();
        }

        //If player death animation is complete, respawn player
        if(!Player::isAlive() && player.animationComplete())
        {
            lifeDisplay.removeLife();
            player.respawn();
        }
    }
}

void Game::updatePlayerProjectiles() {

    const float PROJECTILE_SPEED = 5.f;

    //Iterates through player projectiles and moves them
    for(int i = 0; i < projectiles.size(); i++) projectiles[i].move({0, -PROJECTILE_SPEED});

    //Checks for collisions between player projectiles and enemy sprites
    for(int k = 0; k < projectiles.size();)
    {
        bool hitRegistered = false;

        for(int i = 0; i < enemies.size();)
        {
            if(projectiles[k].getPosition().y < 0)
            {
                hitRegistered = true;
                break;
            }
            else if(enemies[i].getGlobalBounds().intersects(projectiles[k].getGlobalBounds()))
            {
                destroyed.push_back(enemies[i]);
                destroyed.back().destroy();
                enemies.erase(enemies.begin() + i);
                hitRegistered = true;
                topDisplay.addToScore(100);
                break;
            }
            else
            {
                ++i;
            }
        }

        if(hitRegistered)
        {
            projectiles.erase(projectiles.begin() + k);
        }
        else
        {
            ++k;
        }

    }

    //Checks for collision between player projectiles and barriers
    for(int i = 0; i < projectiles.size();)
    {
        bool hitDetected = false;

        for(int j = 0; j < barriers.size(); j++)
        {
            if(barriers[j].getGlobalBounds().intersects(projectiles[i].getGlobalBounds()))
            {
                hitDetected = true;
                break;
            }
        }

        if(hitDetected)
            projectiles.erase(projectiles.begin() + i);
        else
            i++;
    }

    //Checks for collision between UFOs and player projectiles
    for(int k = 0; k < projectiles.size();)
    {
        bool hitRegistered = false;

        for(std::list<UFO>::iterator itr = ufos.begin(); itr != ufos.end(); )
        {
            if(itr->getGlobalBounds().intersects(projectiles[k].getGlobalBounds()))
            {
               itr->destroy();
               hitRegistered = true;
               topDisplay.addToScore(500);
               break;
            }
            else
            {
                ++itr;
            }
        }

        if(hitRegistered)
            projectiles.erase(projectiles.begin() + k);
        else
            ++k;
    }

}

void Game::updateEnemyProjectiles() {

    const float PROJECTILE_SPEED = 5.f;

    //Moves the projectile in down direction
    for(int i = 0; i < enemyProj.size(); i++)   enemyProj[i].move({0,  PROJECTILE_SPEED});

    //Checks if projectile has impacted the player ship or left screen bounds
    for(int i = 0; i < enemyProj.size(); )
    {
        if(enemyProj[i].getPosition().y > VIEW_HEIGHT)                                          //delete if left screen bounds
        {
            enemyProj.erase(enemyProj.begin() + i);
        }
        else if(player.getGlobalBounds().intersects(enemyProj[i].getGlobalBounds()))    //if hit player, delete projectile, destroy player
        {
            enemyProj.erase(enemyProj.begin() + i);
            player.destroy();
        }
        else
        {
            i++;
        }
    }

    //Checks if projectile has impacted any barrier, removes if true
    for(int i = 0; i < enemyProj.size();)
    {
        bool hitDetected = false;
        for(int j = 0; j < barriers.size(); j++)
        {
            if(barriers[j].getGlobalBounds().intersects(enemyProj[i].getGlobalBounds()))
            {
                hitDetected = true;
                break;
            }
        }

        if(hitDetected)
            enemyProj.erase(enemyProj.begin() + i);
        else
           i++;
    }
}

void Game::updateEnemyMovement() {

    const float ENEMY_MOVE_SPEED = 0.5f;

    //Moves all enemies based on current move direction
    if(movDir == EnemyMove::RIGHT)
    {
        for(int i = 0; i < enemies.size(); i++)
            enemies[i].move(ENEMY_MOVE_SPEED, 0);
    }
    else if(movDir == EnemyMove::LEFT)
    {
        for(int i = 0; i < enemies.size(); i++)
            enemies[i].move(-ENEMY_MOVE_SPEED, 0);
    }
    else
    {
        for(int i = 0; i < enemies.size(); i++)
            enemies[i].move(0, 4);
    }

    //Changes move direction from down to either left or right based on previous direction
    if(movDir == EnemyMove::DOWN)
    {
        if(prevDir == EnemyMove::RIGHT)
            movDir = EnemyMove::LEFT;
        else
            movDir = EnemyMove::RIGHT;

        return;
    }

    //Determines if the direction of the enemies need changed before next frame
    for(int i = 0; i < enemies.size(); i++)
    {
        if(enemies[i].getPosition().x + 20 > 256)
        {
            prevDir = EnemyMove::RIGHT;
            movDir = EnemyMove::DOWN;
            break;
        }
        else if(enemies[i].getPosition().x - 2 < 0)
        {
            prevDir = EnemyMove::LEFT;
            movDir = EnemyMove::DOWN;
            break;
        }
    }
}

void Game::updateUFO() {

    //Spawns a UFO
    if(UFO::spawnTime())
    {
        UFO ufo;
        UFO::resetTimer();

        ufos.push_back(ufo);
    }

    //Updates movement of UFO
    for(std::list<UFO>::iterator itr = ufos.begin(); itr != ufos.end(); ++itr)
    {
        if(itr->isAlive())
        {
            if(UFO::getDirection() == EnemyMove::LEFT)
                itr->move({-.5, 0});
            else
                itr->move({+.5, 0});
        }
        //Removes UFO if leaves screen
        else if(itr->getPosition().x > VIEW_WIDTH + 20 || itr->getPosition().x < -20)
        {
            ufos.erase(itr);
            break;
        }
    }
}

void Game::updateEndGameStatus() {

    //Checks if the game has ended if the player is dead and has no more lives left
    if(lifeDisplay.numLives() == 0 && !Player::isAlive())
        gameOver = true;

    //Iterates through enemies to see if enemies have gone below the player, if true, game is over
    for(int i = 0; i < enemies.size(); i++) {
        if (enemies[i].getPosition().y > player.getPosition().y) {
            gameOver = true;
            break;
        }
    }
}

void Game::updateEndOfWave() {
    if(enemies.size() != 0) return;

    //Resets enemies and increments wave
    initializeEnemies();
    topDisplay.nextWave();
}

void Game::updateMenuButton() {
    //Initially sets button to low light every frame
    menuButton.lowlight();

    sf::Vector2i coords = sf::Mouse::getPosition(window);
    sf::Vector2f mousePos = window.mapPixelToCoords(coords);

    //Highlights menu button if mouse is contained in its borders
    if(menuButton.getBounds().contains(mousePos))
        menuButton.highlight();
}