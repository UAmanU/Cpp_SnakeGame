#include "include/game/game.h" //including the Game class declaration for its realisation

#include "include/config/window_settings.h"                                                                                  //including the WindowSettings namespace for creating an InitWindow
#include "include/config/game_settings.h"                                                                                    //including the GameSettings namespace for FPS, tile and scores parameters
#include "include/config/control_settings.h"                                                                                 //including the ControlSettings namespace for updataing snake's delta_x and delta_y attributes depending on what key did user pressed.
#include <algorithm>                                                                                                         //including the STL algorithm for checking if snake crashing into itself.
#include "include/game/game_states.h"                                                                                        //including the GameState enum class for the game loop operator
Game::Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples) : snake(std::move(snake)), apples(std::move(apples)) {}; // Constructor realisation

void Game::update_snake()
{
    if (IsKeyPressed(ControlSettings::MOVE_UP))
    {
        // key_up was pressed - we are changing snake's direction
        snake->delta_y = -1;
        snake->delta_x = 0;
    }
    if (IsKeyPressed(ControlSettings::MOVE_DOWN))
    {
        // key_down was pressed - we are changing snake's direction
        snake->delta_y = 1;
        snake->delta_x = 0;
    }
    if (IsKeyPressed(ControlSettings::MOVE_LEFT))
    {
        // key_left was pressed - we are changing snake's direction
        snake->delta_x = -1;
        snake->delta_y = 0;
    }
    if (IsKeyPressed(ControlSettings::MOVE_RIGHT))
    {
        // key_right was pressed - we are changing snake's direction
        snake->delta_x = 1;
        snake->delta_y = 0;
    }
    // Checking if snake ate an apple.
    for (auto &apple : apples)
    {
        if (apple.vector[0].x == snake->vector[0].x && apple.vector[0].y == snake->vector[0].y)
        {
            snake->vector.push_back(apple.vector[0]);     // pushing back the new block to the snake->vector.
            score += GameSettings::SCORES_FOR_EACH_APPLE; // adding score
            apple.move();                                 // moving apple to the random position
        }
    }
}

bool Game::check_snake_validality() const
{
    // snake in field condition
    if (snake->vector[0].x <= WindowSettings::WIDTH && snake->vector[0].x >= 0 && snake->vector[0].y <= WindowSettings::HEIGHT && snake->vector[0].y >= 0)
    {
        return false;
    };
    // snake doesn't crash into itself condition
    for (int i = 1; i < snake->vector.size(); i++)
    {
        Vector2 coords = snake->vector[i];
        if (coords.x == snake->vector[0].x && coords.x == snake->vector[0].y && i != snake->vector.size() - 1)
        {
            return false;
        }
    }
    return true; // returning the and condition of both of these conditions
}

bool Game::check_win() const
{
    // checking the win
    return score >= GameSettings::SCORES_FOR_WIN;
}
bool Game::start_game()
{
    GameState game_state = GameState::Menu; // game loop operator. The game is starting with menu.
    // Game loop
    while (!(WindowShouldClose()))
    {
        // Input
        update_snake();
        // Input

        // Update
        if (!check_snake_validality())
            return false;
        snake->move();
        if (check_win())
            return true;
        // Update

        // Drawing
        renderer.draw_field();
        renderer.draw_all_apples(apples);
        renderer.draw_snake(*snake);
        renderer.draw_scoreboard(score);
        // Drawing
    }
    return true;
    // Game loop
}
