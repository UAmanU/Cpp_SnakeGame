#pragma once

#include "game_settings.h" //including for InitWindow size settings.

#include <string> //Including the STL string for InitWindow's name.

/*In this file, there's a WindowSettings namespace.
All namespace's variables are inline - type, so there's no .cpp realisation files
in WindowSettings namespace, there's a InitWindow's settings like width, height and name.*/

namespace WindowSettings
{
    inline const int HEIGHT = GameSettings::TILE_Y_AMOUNT * GameSettings::TILE_LENGTH; // Window's height based on how many Y tiles in field and how big they are.
    inline const int WIDTH = GameSettings::TILE_X_AMOUNT * GameSettings::TILE_LENGTH;  // Window's width based on how many X tiles in fiels and how big they are.
    inline const std::string NAME = "Snake game by Aman U!";                           // InitWindow's name.
    inline bool CURSOR_ENABLED = true;                                                 // CursorEnabling parametr

};
