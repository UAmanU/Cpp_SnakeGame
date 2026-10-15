#include "include/object/apple.h"
#include "include/config/game_settings.h"

#include <raylib.h>

void Apple::move()
{
    Vector2 &apple_vector = vector[0];
    apple_vector.x = GetRandomValue(0, GameSettings::TILE_X_AMOUNT) * GameSettings::TILE_LENGTH;
    apple_vector.y = GetRandomValue(0, GameSettings::TILE_Y_AMOUNT) * GameSettings::TILE_Y_AMOUNT;
}