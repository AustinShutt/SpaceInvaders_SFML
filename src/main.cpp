#include "Game.h"

int main()
{

    AssetManager::loadAssets();

    Game game;
    game.Run();

    return 0;
}