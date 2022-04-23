//
// Created by Austin on 4/22/2022.
//

#include "Game.h"

Game::Game() {
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");    //Creates Window
    sf::View view({VIEW_WIDTH/2.f, VIEW_HEIGHT/2.f},{VIEW_WIDTH, VIEW_HEIGHT} );            //Sets window view
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
        player.move(-PLAYER_MOVE_SPEED, 0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(PLAYER_MOVE_SPEED, 0);
}
void Game::Update() {

    enemyFire();
    updateEnemyProjectiles();
    updatePlayerProjectiles();

    if(movDir == EnemyMove::RIGHT)
    {
        for(auto& itr : enemies)
            itr.move(ENEMY_MOVE_SPEED, 0);
    }
    else if(movDir == EnemyMove::LEFT)
    {
        for(auto& itr : enemies)
            itr.move(-ENEMY_MOVE_SPEED, 0);
    }
    else
    {
        for(auto& itr : enemies)
            itr.move(0, 4);
    }


    if(movDir == EnemyMove::DOWN)
    {
        if(prevDir == EnemyMove::RIGHT)
            movDir = EnemyMove::LEFT;
        else
            movDir = EnemyMove::RIGHT;

        return;
    }

    for(auto& itr : enemies)
    {
        if(itr.getPosition().x + 20 > 256)
        {
            prevDir= EnemyMove::RIGHT;
            movDir = EnemyMove::DOWN;
            break;
        }
        else if(itr.getPosition().x - 2 < 0)
        {
            prevDir=EnemyMove::LEFT;
            movDir = EnemyMove::DOWN;
            break;
        }
    }
}

void Game::Render() {
    window.clear();
    window.draw(background);
    window.draw(player);
    for(auto& itr: barriers) window.draw(itr);
    for(auto& itr : enemies)      window.draw(itr);
    for(auto& itr : projectiles) window.draw(itr);
    for(auto& itr : enemyProj)   window.draw(itr);
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

    //TODO: Add cool down to ship fire ability
    Projectile proj;
    proj.setPosition(player.getPosition());
    projectiles.push_back(proj);
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


void Game::updatePlayerProjectiles() {

    for(auto& itr : projectiles) itr.move({0, -PROJECTILE_SPEED});

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
                enemies.erase(enemies.begin() + i);
                hitRegistered = true;
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
    for(auto& itr : enemyProj)   itr.move({0,  PROJECTILE_SPEED});

    for(int i = 0; i < enemyProj.size(); )
    {
        if(enemyProj[i].getPosition().y > VIEW_HEIGHT)
        {
            enemyProj.erase(enemyProj.begin() + i);
        }
        else if(player.getGlobalBounds().intersects(enemyProj[i].getGlobalBounds()))
        {
            //TODO: Player Hit, lose life.
            enemyProj.erase(enemyProj.begin() + i);
        }
        else
        {
            i++;
        }
    }

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
