#include "include/game.h"

#include "include/config/window_settings.h"
#include "include/config/game_settings.h"
#include "include/config/control_settings.h"
#include "include/config/colors_settings.h"
#include <raylib.h>

Game::Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples) : snake(std::move(snake)), apples(std::move(apples)) {};

void Game::draw_apples() const
{
    for (const Apple &apple : apples)
    {
        int apple_radius = GameSettings::TILE_LENGTH / 2;
        const int center_x = apple.vector[0].x + apple_radius;
        const int center_y = apple.vector[0].y - apple_radius;
        DrawCircle(center_x, center_y, apple_radius, apple.color);
    }
}
void Game::draw_snake() const
{
    for (const auto &coords : snake->vector)
    {
        DrawRectangle(coords.x, coords.y, 20, 20, ColorsSettings::SNAKE);
    }
}
void Game::update_snake()
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
    for (auto &apple : apples)
    {
        for (const auto &coords : snake->vector)
        {
            if (apple.vector[0].x == coords.x && apple.vector[0].y == coords.y)
            {
                snake->vector.push_back(apple.vector[0]);
                apple.move();
                return;
            }
        }
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

    while (!(WindowShouldClose()))
    {
        if (check_exit())
            break;

        update_snake();

        if (!check_snake_validality())
            break;

        BeginDrawing();
        ClearBackground(ColorsSettings::FIELD);
        draw_snake();
        draw_apples();
        EndDrawing();
        }
    CloseWindow();
}
