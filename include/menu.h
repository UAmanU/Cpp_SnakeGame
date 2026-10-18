#pragma once

/*In this file, there's a declaration of Menu class.
It doesn't own anything and its main responbility is to control the Window while GameState is Menu or Restart.
In future, there will be MenuRenderer for better responbility separation.*/

class Menu
{
public:
    Menu() = default;          // Default constructor
    ~Menu() = default;         // Default destructor
    void render();             // This method renders Menu interface in InitWindow.
    bool user_wants_to_play(); // this method returns true if user clicked Enter
};