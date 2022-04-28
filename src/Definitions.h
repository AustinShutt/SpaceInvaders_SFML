//
// Created by Austin on 4/22/2022.
//

#ifndef INC_28_SPACEINVADERS_DEFINITIONS_H
#define INC_28_SPACEINVADERS_DEFINITIONS_H


enum class EnemyType {ONE = 0, TWO, THREE, FOUR};
enum class EnemyMove {RIGHT, DOWN, LEFT};

const unsigned int WINDOW_WIDTH      = 512;
const unsigned int WINDOW_HEIGHT     = 768;
const unsigned int VIEW_WIDTH        = 256;
const unsigned int VIEW_HEIGHT       = 384;
const float        TIME_STEP         = 1.f/60.f;

#endif //INC_28_SPACEINVADERS_DEFINITIONS_H
