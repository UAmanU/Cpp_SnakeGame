#include "include/menu.h"                    //including the Menu class that will be realised in this file.
#include "lib/raylib.h"                      //including the lib for rendering and controlling the InitWindow.
#include "include/config/menu_settings.h"    //including the MenuSettings namespace for Button coordinates , text and etc.
#include "include/config/colors_settings.h"  //including the ColorsSettings namespace for Button colors, MenuBackgrouncdColor and etc.
#include "include/config/control_settings.h" //including the ControlSettings namespace for checking if user wants to restart the game

/*So i want Menu class returns bool states to ProgrammLauncher and ProgrammLauncher will do something depending on that Menu returned.*/
void Menu::render_start_game_button() const
{
    // Drawing the Start Game button.
    DrawRectangle(MenuSettings::GAME_BUTTON_BOX.x, MenuSettings::GAME_BUTTON_BOX.y, MenuSettings::GAME_BUTTON_BOX.width, MenuSettings::GAME_BUTTON_BOX.height, ColorsSettings::BUTTONS_COLOR);
    DrawText(MenuSettings::START_GAME_TEXT.c_str(), MenuSettings::START_GAME_TEXT_POSITION.x, MenuSettings::START_GAME_TEXT_POSITION.y, MenuSettings::TEXT_FONT_SIZE, ColorsSettings::BUTTONS_TEXT_COLOR);
    // Drawing the Start Game button
}

bool Menu::user_wants_to_start_game() const
{
    Vector2 click_coordinates = GetMouseDelta(); // geting the click position
    return CheckCollisionPointRec(click_coordinates, MenuSettings::GAME_BUTTON_BOX);
}
void Menu::render_menu() const
{
    ClearBackground(ColorsSettings::MENU_BACKGROUND_COLOR); // clearing the background color
    render_start_game_button();
}
void Menu::render_aftergame_menu(const bool game_result) const
{
    // Clearing Background color after the game.
    ClearBackground(ColorsSettings::MENU_BACKGROUND_COLOR);
    // getting the result text of the game.
    const char *result_text = (game_result ? MenuSettings::WIN_TEXT : MenuSettings::LOSE_TEXT).c_str();
    // texting it using config data
    DrawText(result_text, MenuSettings::RESULT_TEXT_POSITION.x, MenuSettings::RESULT_TEXT_POSITION.y, MenuSettings::TEXT_FONT_SIZE, ColorsSettings::BUTTONS_TEXT_COLOR);
    // texting the restart instruction text using config data.
    DrawText(MenuSettings::RESTART_INSTRUCTION_TEXT.c_str(), MenuSettings::RESTART_INSTRUCTION_TEXT_POSITION.x, MenuSettings::RESTART_INSTRUCTION_TEXT_POSITION.y, MenuSettings::TEXT_FONT_SIZE, ColorsSettings::BUTTONS_TEXT_COLOR);
}
bool Menu::user_wants_to_restart() const
{
    return IsKeyPressed(ControlSettings::RESTART);
}