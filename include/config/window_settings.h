#pragma once

#include "game_settings.h"

#include <string>

namespace WindowSettings
{
    inline const int HEIGHT = GameSettings::TILE_Y_AMOUNT * GameSettings::TILE_LENGTH;
    inline const int WIDTH = GameSettings::TILE_X_AMOUNT * GameSettings::TILE_LENGTH;
    inline const std::string NAME = "Snake game by Aman U!";
    inline bool CURSOR_ENABLED = false;

};
