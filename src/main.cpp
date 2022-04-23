#include "Game.h"
#include <cstdlib>
#include <ctime>

int main()
{

    srand((unsigned) time(nullptr) );

    AssetManager::loadAssets();
    Game game;
    game.Run();

    return 0;
}