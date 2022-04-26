//
// Created by Austin on 4/22/2022.
//

#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");    //Creates Window
    sf::View view({VIEW_WIDTH/2.f, VIEW_HEIGHT/2.f},{VIEW_WIDTH, VIEW_HEIGHT} );//Sets window view


    window.setView(view);

    initializeBarriers();
    initializeEnemies();
}

void Game::Run() {

    sf::Clock clock;            //SFML clock, reset each cycle and returns time in seconds between calls
    float elapsedTime = 0.f;    //Holds accumulated value of time between cycles

    while (window.isOpen())
    {
        elapsedTime += clock.restart().asSeconds(); //Resets clock, adds time between cycle

        while (elapsedTime >= TIME_STEP)            //Limits update to 60fps
        {
            HandleInput();                          //Accepts input from user
            Update();                               //Updates the scene

            elapsedTime -= TIME_STEP;               //Removes value of time step from time accumulator
        }

        Render();                                   //Draws the scene to the SFML window
    }
}

void Game::HandleInput() {

    //Poll events
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        if(event.type == sf::Event::KeyPressed)
        {
            if(event.key.code == sf::Keyboard::Space)
                shipFire();
        }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        if(player.getPosition().x > player.getGlobalBounds().width/2)
            player.move(-PLAYER_MOVE_SPEED, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        if(player.getPosition().x < VIEW_WIDTH - player.getGlobalBounds().width/2)
            player.move(PLAYER_MOVE_SPEED, 0);
}
void Game::Update() {
    Player::update();
    Enemy::update();

    enemyFire();
    updateEnemyProjectiles();
    updatePlayerProjectiles();
    updateEnemyMovement();
    updateShipAnimations();
}
void Game::Render() {
    window.clear();
    window.draw(background);

    if(Player::isAlive() == true)
        window.draw(player);
    else
        window.draw(player.getDeathAnimation());

    for(int i = 0; i < barriers.size();    i++) window.draw(barriers[i]);
    for(std::list<Enemy>::iterator itr = destroyed.begin(); itr != destroyed.end(); ++itr) window.draw(*itr);
    for(int i = 0; i < enemies.size();     i++) window.draw(enemies[i]);
    for(int i = 0; i < projectiles.size(); i++) window.draw(projectiles[i]);
    for(int i = 0; i < enemyProj.size();   i++) window.draw(enemyProj[i]);
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
        for(std::__cxx11::list<Enemy>::iterator itr = destroyed.begin(); itr != destroyed.end(); ++itr)
            itr->updateAnimation();

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

    for(int i = 0; i < projectiles.size(); i++) projectiles[i].move({0, -PROJECTILE_SPEED});

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


    for(int i = 0; i < projectiles.size();)
    {
        bool hitDetected = false;

        for(int j = 0; j < barriers.size(); j++)
        {
            if(barriers[j].getGlobalBounds().intersects(projectiles[i].getGlobalBounds()))
            {
                barriers[j].hitRegister();
                if(barriers[j].isDestroyed())
                    barriers.erase(barriers.begin() + j);

                hitDetected = true;
                break;
            }
        }

        if(hitDetected)
            projectiles.erase(projectiles.begin() + i);
        else
            i++;
    }
}

void Game::updateEnemyProjectiles() {

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
                barriers[j].hitRegister();
                if(barriers[j].isDestroyed())
                    barriers.erase(barriers.begin() + j);

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
