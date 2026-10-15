#include "include/game.h"

#include "include/config/window_settings.h"

#include <raylib.h>

Game::Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples) : snake(std::move(snake)), apples(std::move(apples)) {};

void Game::prepare()
{
    InitWindow(WindowSettings::WIDTH, WindowSettings::HEIGHT, WindowSettings::NAME.c_str());
    if (!WindowSettings::CURSOR_ENABLED)
    {
        EnableCursor();
    }
}