#include "include/game.h"

#include "include/config/window_settings.h"
#include "include/config/game_settings.h"
#include "include/config/control_settings.h"

#include <raylib.h>

Game::Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples) : snake(std::move(snake)), apples(std::move(apples)) {};

void Game::draw_apples() const
{
    for (const Apple &apple : apples)
    {
        const int radius = GameSettings::TILE_LENGTH / 2;
        const int center_x = apple.vector[0].x + GameSettings::TILE_LENGTH / 2;
        const int center_y = apple.vector[0].y - GameSettings::TILE_LENGTH / 2;
        DrawCircle(center_x, center_y, radius, apple.color);
    }
}
void Game::update_snake_position()
{
    if (IsKeyPressed(ControlSettings::MOVE_UP))
    {
        snake->delta_y = -1;
    }
    if (IsKeyPressed(ControlSettings::MOVE_DOWN))
    {
        snake->delta_y = 1;
    }
    if (IsKeyPressed(ControlSettings::MOVE_LEFT))
    {
        snake->delta_x = -1;
    }
    if (IsKeyPressed(ControlSettings::MOVE_RIGHT))
    {
        snake->delta_y = 1;
    }
}
bool Game::check_exit()
{
    return (IsKeyPressed(ControlSettings::EXIT));
}
bool Game::check_snake_validality() const
{
    return (snake->vector[0].x <= WindowSettings::WIDTH && snake->vector[0].y <= WindowSettings::HEIGHT);
}
void Game::prepare()
{
    InitWindow(WindowSettings::WIDTH, WindowSettings::HEIGHT, WindowSettings::NAME.c_str());
    SetTargetFPS(GameSettings::FPS);

    if (!WindowSettings::CURSOR_ENABLED)
    {
        EnableCursor();
    }
}
void Game::start_game()
{
    prepare();

    while (WindowShouldClose())
    {
        if (check_exit())
            break;

        update_snake_position();

        if (!check_snake_validality())
            break;

        BeginDrawing();

        draw_apples();
    }
    CloseWindow();
}
