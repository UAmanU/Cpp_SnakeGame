/*in this file, there's a realisation of GameRenderer class*/
#include "include/game/game_renderer.h"     //including the file where GameRenderer class was declared
#include "lib/raylib.h"                     //including the library for drawing objects in InitWindow.
#include "include/config/game_settings.h"   //including the GameSettings namespace for evaluating apple's radius and lines amount.
#include "include/config/colors_settings.h" //including the ColorsSettings for drawing grass and separating lines in InitWindow
#include <string>                           //including the STL string for rendering a scoreboard.
void GameRenderer::draw_apple(const Apple &apple) const
{
    int apple_radius = GameSettings::TILE_LENGTH / 2;      // evaluting the apple radius for drawing a circle.
    const int center_x = apple.vector[0].x + apple_radius; // evaluating circle center's coordinates for correct circle drawing
    const int center_y = apple.vector[0].y + apple_radius;
    DrawCircle(center_x, center_y, apple_radius, apple.color); // drawing apple in InitWindow
}
void GameRenderer::draw_all_apples(const std::vector<Apple> &apples) const
{
    for (const Apple &apple : apples)
    {
        draw_apple(apple); // calling draw_apple() for every Apple in vector
    }
}
void GameRenderer::draw_snake(const Snake &snake) const
{
    for (const auto &coords : snake.vector)
    {
        DrawRectangle(coords.x, coords.y, GameSettings::TILE_LENGTH, GameSettings::TILE_LENGTH, snake.color); // drawing the square for each snake body's part with its color.
    }
}
void GameRenderer::draw_field() const
{
    ClearBackground(ColorsSettings::FIELD); // Clearing the Background
    int j = 1;
    for (int i = 1; i < GameSettings::TILE_X_AMOUNT; i++)
    {
        DrawLine(i * GameSettings::TILE_LENGTH, 0, i * GameSettings::TILE_LENGTH, GameSettings::TILE_Y_AMOUNT * GameSettings::TILE_LENGTH, ColorsSettings::LINES);
        DrawLine(0, j * GameSettings::TILE_LENGTH, GameSettings::TILE_X_AMOUNT * GameSettings::TILE_LENGTH, j * GameSettings::TILE_LENGTH, ColorsSettings::LINES);
        j++;
    }
    // i - is an iterator for drawing | | | lines, j - is an iterator for drawing ___ lines
}
void GameRenderer::draw_scoreboard(size_t score) const

{
    const std::string scoreboard = "Score: " + std::to_string(score);                                                                                             // creating a std::string variant of gameboard
    DrawText(scoreboard.c_str(), GameSettings::SCOREBOARD_X_POS, GameSettings::SCOREBOARD_Y_POS, GameSettings::SCOREBOARD_FONT_SIZE, ColorsSettings::SCOREBOARD); // rendering the scoreboard in InitWindow
}