//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_DEFINITIONS_H
#define INC_28_SPACEINVADERS_DEFINITIONS_H

enum class EnemyType {ONE = 0, TWO, THREE, FOUR};
enum class EnemyMove {RIGHT, DOWN, LEFT};

constexpr unsigned int WINDOW_WIDTH      = 512;
constexpr unsigned int WINDOW_HEIGHT     = 768;
constexpr unsigned int VIEW_WIDTH        = 256;
constexpr unsigned int VIEW_HEIGHT       = 384;
constexpr float        TIME_STEP         = 1.f/60.f;

constexpr float        ENEMY_MOVE_SPEED  = 0.5f;
constexpr float        PLAYER_MOVE_SPEED = 1.0f;
constexpr float        PROJECTILE_SPEED  = 5.f;
constexpr unsigned int PROJECTILE_DAMAGE = 1u;
constexpr float        ENEMY_FIRE_CD     = .75f;

#endif //INC_28_SPACEINVADERS_DEFINITIONS_H
