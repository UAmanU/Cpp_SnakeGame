#pragma once

/*In this file, there's an enum class GameState.
GameState has 3 types: Game, Menu and Restart.
GameState allows to control game loop.
For example: we can create a GameState-type variable and game loop will take inputs, updates and drawing depending on what exactly type is this variable.*/

enum class GameState
{
    Game,    // Game loop.
    Menu,    // Before Game loop.
    Restart, // After Game loop.
};