#pragma once

/*In this file, there's a declaration of Menu class.
It doesn't own anything and its main responbility is to control the Window while GameState is Menu or Restart.
In future, there will be MenuRenderer for better responbility separation.*/

class Menu
{
private:
    void render_start_game_button() const;

public:
    Menu() = default;                                         // Default constructor
    ~Menu() = default;                                        // Default destructor
    void render_aftergame_menu(const bool game_result) const; // this method renders after-game menu.
    void render_menu() const;                                 // This method renders Menu interface in InitWindow.
    bool user_wants_to_restart() const;                       // this method returns true if user clicked Enter
    bool user_wants_to_start_game() const;                    // this method returns true if user clicked the button.
};