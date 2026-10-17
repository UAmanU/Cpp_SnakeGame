#pragma once

/*In this file, there's a GameSettings namespace. all its variables are inline, so there's no .cpp realisation files.
GameSettings namespace's variables is for global game setting like how many X tiles will be in Window, max apple amount and snake's start spawpoint*/

namespace GameSettings
{
    inline constexpr int SCOREBOARD_X_POS = 20;     // ScoreBoard Position
    inline constexpr int SCOREBOARD_Y_POS = 20;     // ScoreBoard Position
    inline constexpr int SCOREBOARD_FONT_SIZE = 20; // ScoreBoard font size

    inline constexpr int TILE_X_AMOUNT = 30; // Field's width in tiles
    inline constexpr int TILE_Y_AMOUNT = 30; // Field's height in tiles
    inline int TILE_LENGTH = 20;             // Tile's length in pixels
    inline int FPS = 10;                     // Frames Per Second
    inline int MAX_APPLES_AMOUNT = 5;        // Apples amount
    inline int SCORES_FOR_EACH_APPLE = 10;   // How many score will player earn after eating an apple.
    inline int SCORES_FOR_WIN = 100;         // How many scores player needs to have for winning
    inline int SNAKE_SPAWNPOINT_X = 400;     // Snake start Position
    inline int SNAKE_SPAWNPOINT_Y = 400;     // Snake start Position
    inline int SNAKE_START_SIZE = 3;         // Snake start size
};