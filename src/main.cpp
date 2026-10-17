#include "include/game/game.h" //including the Game class for launching the game loop

#include "include/config/game_settings.h"   //including the GameSettings namespace for creating a snake smart_pointer and vector of Apples
#include "include/config/colors_settings.h" //including the ColorSettings namespace for snake's and apple's color.

/*main.cpp - is a file where int main() func is realised.
At the moment, there're 2 others functions - get_snake_coords() and get_apples(). They're temporary and will be moved to GameLauncher class soon
So, main func creates all needed variables for Game class and launching the Game::start_game method.*/

std::vector<Vector2> get_snake_coords()
{
    // This function returns the start coordinates for snake using while loop and GameSettings variables.
    std::vector<Vector2> snake_vector;

    int i = 0;
    while (i < GameSettings::SNAKE_START_SIZE)
    {
        Vector2 current_snake_coords = {GameSettings::SNAKE_SPAWNPOINT_X, GameSettings::SNAKE_SPAWNPOINT_Y - GameSettings::TILE_LENGTH * i};
        snake_vector.push_back(current_snake_coords);
        i++;
    }
    return snake_vector;
}

std::vector<Apple> get_apples()
{
    // This function returns the vector of Apple-type object using while loop and GameSettings variables.
    std::vector<Apple> apples;

    int i = 0;
    while (i < GameSettings::MAX_APPLES_AMOUNT)
    {
        int apple_x = GetRandomValue(0, GameSettings::TILE_X_AMOUNT - 1) * GameSettings::TILE_LENGTH;
        int apple_y = GetRandomValue(0, GameSettings::TILE_Y_AMOUNT - 1) * GameSettings::TILE_LENGTH;
        Vector2 coords = {apple_x, apple_y};
        Apple apple = Apple(coords, ColorsSettings::APPLE);
        apples.push_back(std::move(apple));
        i++;
    }
    return apples;
}

int main()
{

    auto snake_vector = get_snake_coords();                                                                 // std::vector<Vector2> variable
    std::unique_ptr<Snake> snake = std::make_unique<Snake>(std::move(snake_vector), ColorsSettings::SNAKE); // moving snake_vector variable to the new smart_pointer snake.
    std::vector<Apple> apples = get_apples();                                                               // getting apples vector.
    std::unique_ptr<Game> game = std::make_unique<Game>(std::move(snake), std::move(apples));               // creating the new Game smart_pointer and moving Snake and apples to it.
    game->prepare();                                                                                        // calling the method for InitWindow() SetUp
    game->start_game();                                                                                     // calling the method for game loop's running.

    return 0;
}
