cmake_minimum_required(VERSION 3.22)
project(28_SpaceInvaders)

set(CMAKE_CXX_STANDARD 17)

add_executable(28_SpaceInvaders src/main.cpp src/Game.cpp src/Game.h src/Definitions.h src/Player.cpp src/Player.h src/Enemy.cpp src/Enemy.h src/Barrier.cpp src/Barrier.h src/Background.cpp src/Background.h src/Projectile.cpp src/Projectile.h src/AssetManager.cpp src/AssetManager.h src/LifeDisplay.cpp src/LifeDisplay.h src/TopDisplay.cpp src/TopDisplay.h src/UFO.cpp src/UFO.h src/BaseState.h src/AppManager.cpp src/AppManager.h src/MainMenu.cpp src/MainMenu.h src/Button.cpp src/Button.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${PROJECT_SOURCE_DIR}/../SFML_MinGW_64x_7.3.0/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics)

include_directories(${PROJECT_SOURCE_DIR}/SFML_MinGW_64x_7.3.0/SFML-2.5.1/include)
target_link_libraries(28_SpaceInvaders sfml-system sfml-window sfml-graphics)