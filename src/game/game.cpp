#include "include/game.h"
#include "include/game_renderer.h"
#include "include/config/window_settings.h"
#include "include/config/game_settings.h"
#include "include/config/control_settings.h"
#include "include/config/colors_settings.h"
#include <raylib.h>

Game::Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples) : snake(std::move(snake)), apples(std::move(apples)) {};

void Game::update_snake()
{
    if (IsKeyPressed(ControlSettings::MOVE_UP))
    {
        snake->delta_y = -1;
        snake->delta_x = 0;
    }
    if (IsKeyPressed(ControlSettings::MOVE_DOWN))
    {
        snake->delta_y = 1;
        snake->delta_x = 0;
    }
    if (IsKeyPressed(ControlSettings::MOVE_LEFT))
    {
        snake->delta_x = -1;
        snake->delta_y = 0;
    }
    if (IsKeyPressed(ControlSettings::MOVE_RIGHT))
    {
        snake->delta_x = 1;
        snake->delta_y = 0;
    }
    for (auto &apple : apples)
    {
        if (apple.vector[0].x == snake->vector[0].x && apple.vector[0].y == snake->vector[0].y)
        {
            snake->vector.push_back(apple.vector[0]);
            score += GameSettings::SCORES_FOR_EACH_APPLE;
            apple.move();
        }
    }
}

bool Game::check_exit()
{
    return (IsKeyPressed(ControlSettings::EXIT));
}
bool Game::check_snake_validality() const
{
    return snake->vector[0].x <= WindowSettings::WIDTH && snake->vector[0].x >= 0 && snake->vector[0].y <= WindowSettings::HEIGHT && snake->vector[0].y >= 0;
}
void Game::prepare()
{
    InitWindow(WindowSettings::WIDTH, WindowSettings::HEIGHT, WindowSettings::NAME.c_str());
    SetTargetFPS(GameSettings::FPS);

    if (WindowSettings::CURSOR_ENABLED)
    {
        EnableCursor();
    }
}
bool Game::check_win() const
{
    return score >= GameSettings::SCORES_FOR_WIN;
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
        snake->move();
        if (check_win())
            break;
        BeginDrawing();
        renderer.draw_field();
        renderer.draw_all_apples(apples);
        renderer.draw_snake(*snake);
        renderer.draw_scoreboard(score);
        EndDrawing();
    }
    CloseWindow();
}
