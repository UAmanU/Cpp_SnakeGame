#pragma once

#include <memory>              //Including the STL memory for ProgrammLauncher's smart pointer attributes.
#include "include/game/game.h" //including the Game class for launching it and controlling it.
#include "include/menu.h"      //including the Menu class for controlling it.

/*In this file, there's a ProgrammLauncher class declaration.
His main responbility is controlling the Game, Menu and Restart states.
It owns the smart_pointer to Game and Menu.*/

class ProgrammLauncher
{
private:
    std::unique_ptr<Game> game;                    // smart pointer to Game class object.
    std::unique_ptr<Menu> menu;                    // smart pointer to Menu class object.
    std::vector<Vector2> get_snake_vector() const; // returns vector for snake (snake will be moved to game.)
    std::vector<Apple> get_apples_vector() const;  // returns apples vector (it will be moved to game.)
public:
    ProgrammLauncher() = default;  // default constructor
    ~ProgrammLauncher() = default; // default destructor
    void prepare();                // method that prepares the menu and game for launch_programm() and InitWindow
    void launch_programm();        // main method that connects menu and game.
};