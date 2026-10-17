#include "include/object/apple.h"         //including the Apple struct's declaration
#include "include/config/game_settings.h" //including the GameSettings namespace for evaluating the apple's coordinates.

Apple::Apple(Vector2 coords, Color color) : Object({coords}, color) {}

void Apple::move()
{
    Vector2 &apple_vector = vector[0];
    apple_vector.x = GetRandomValue(0, GameSettings::TILE_X_AMOUNT - 1) * GameSettings::TILE_LENGTH;
    apple_vector.y = GetRandomValue(0, GameSettings::TILE_Y_AMOUNT - 1) * GameSettings::TILE_LENGTH;
}
