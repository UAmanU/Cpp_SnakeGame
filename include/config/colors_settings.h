#pragma once
#include "lib/raylib.h" //including the library for creating a new inline Color-type variables.

/*In this file, there's a ColorsSetting namespace with colors.
All Colors are inline variables, so there's no color_settings realisation .cpp file*/

namespace ColorsSettings
{
    inline constexpr Color SNAKE = BLUE;        // Snake color
    inline constexpr Color APPLE = RED;         // Apple color
    inline constexpr Color FIELD = GREEN;       // Background color
    inline constexpr Color LINES = BLACK;       // Separating files color
    inline constexpr Color SCOREBOARD = PURPLE; // Scoreboard text's color
};