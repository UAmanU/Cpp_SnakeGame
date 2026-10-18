#pragma once
#include "lib/raylib.h" //including the lib for Color, Vector2-type variables.
#include <string>       //including the STL string for START_GAME_TEXT variable
/*In this file, there's a namespace MenuSettings.
MenuSettings has inline variables with Color or Vector2 types.
For example: inline constexpr Color BACKGROUND_COLOR = YELLOW;*/

namespace MenuSettings
{

    inline constexpr Rectangle GAME_BUTTON_BOX = {200, 200, 200, 100};                 // Start game button hitboxes
    inline const std::string START_GAME_TEXT = "Start Game";                           // Start game button text
    inline constexpr int TEXT_FONT_SIZE = 30;                                          // Text's Font size
    inline constexpr Vector2 START_GAME_TEXT_POSITION = {225, 225};                    // Start game button text's position
    inline constexpr Vector2 RESULT_TEXT_POSITION = {300, 300};                        // Result text's position in after-game menu
    inline const std::string WIN_TEXT = "You won!";                                    // Text in after-game menu if user won.
    inline const std::string LOSE_TEXT = "You lost!";                                  // Text in after-game menu if user lost.
    inline constexpr Vector2 RESTART_INSTRUCTION_TEXT_POSITION = {350, 350};           // Text to instruct the user how to restart the game's position
    inline const std::string RESTART_INSTRUCTION_TEXT = "Press Enter to start again."; // Text to instruct the user how to restart the game.

};