#pragma once

#include "lib/raylib.h" //including the lib for creating the enum variables.

/*In this file, there's a ControlSettings namespace. all its variables are inline, so there's no .cpp realisation files.
ControlSettings namespace's variables is for game controlling.*/

namespace ControlSettings
{
    inline int EXIT = KEY_ESCAPE; // Close the window

    inline int MOVE_UP = KEY_UP;       // Snake moves up
    inline int MOVE_LEFT = KEY_LEFT;   // Snake moves left
    inline int MOVE_RIGHT = KEY_RIGHT; // Snake moves right
    inline int MOVE_DOWN = KEY_DOWN;   // Snake moves down

    inline int RESTART = KEY_ENTER; // Restarting the game
};