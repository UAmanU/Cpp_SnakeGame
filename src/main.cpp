#include "include/game.h"

#include "include/config/game_settings.h"
#include "include/config/colors_settings.h"

std::vector<Vector2> get_snake_coords()
{
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
    std::vector<Apple> apples;

    int i = 0;
    while (i < GameSettings::MAX_APPLES_AMOUNT)
    {
        int apple_x = GetRandomValue(0, GameSettings::TILE_X_AMOUNT - 1) * GameSettings::TILE_LENGTH;
        int apple_y = GetRandomValue(0, GameSettings::TILE_Y_AMOUNT - 1) * GameSettings::TILE_LENGTH;
        Apple apple = Apple({apple_x, apple_y}, ColorsSettings::APPLE);
        apples.push_back(std::move(apple));
        i++;
    }
    return apples;
}
int main()
{
    // Code
    auto snake_vector = get_snake_coords();
    std::unique_ptr<Snake> snake = std::make_unique<Snake>(std::move(snake_vector), ColorsSettings::SNAKE);
    std::vector<Apple> apples = get_apples();
    std::unique_ptr<Game> game = std::make_unique<Game>(std::move(snake), std::move(apples));
    game->prepare();
    game->start_game();
    // Code

    return 0;
}
