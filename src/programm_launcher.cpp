#include "include/programm_launcher.h"       //Including the ProgrammLauncher class that will be realised in this file.
#include "include/config/game_settings.h"    //includig the GameSettings namespace for prepare() method.
#include "include/config/colors_settings.h"  //including the ColorsSettings namespace for prepare() method.
#include "include/game/game_states.h"        //including the GameState enum class for programm loop operator
#include "include/config/window_settings.h"  //including the WindowSettings namespace for creating an InitWindow
#include "include/config/control_settings.h" //including the ControlSettings namespace for checking if user wants to close the window
std::vector<Vector2> ProgrammLauncher::get_snake_vector() const
{
    // This function returns the start coordinates for snake using while loop and GameSettings variables.
    std::vector<Vector2> snake_vector;

    int i = 0;
    while (i < GameSettings::SNAKE_START_SIZE)
    {
        Vector2 current_snake_coords = {GameSettings::SNAKE_SPAWNPOINT_X, GameSettings::SNAKE_SPAWNPOINT_Y - GameSettings::TILE_LENGTH * i};
        snake_vector.push_back(current_snake_coords);
        i++;
    }
    return snake_vector;
}
std::vector<Apple> ProgrammLauncher::get_apples_vector() const
{
    // This function returns the vector of Apple-type object using while loop and GameSettings variables.
    std::vector<Apple> apples; // vector declaration

    int i = 0;                                  // iterator
    while (i < GameSettings::MAX_APPLES_AMOUNT) // loop
    {
        int apple_x = GetRandomValue(0, GameSettings::TILE_X_AMOUNT - 1) * GameSettings::TILE_LENGTH; // evaluating random x coordinates for current apple
        int apple_y = GetRandomValue(0, GameSettings::TILE_Y_AMOUNT - 1) * GameSettings::TILE_LENGTH; // evaluating random y coordinates for current apple
        Vector2 coords = {apple_x, apple_y};                                                          // creating a Vector2 of random coordinates
        Apple apple = Apple(coords, ColorsSettings::APPLE);                                           // creating an apple-type object
        apples.push_back(std::move(apple));                                                           // moving it to vector
        i++;                                                                                          // iterator
    }
    return apples; // returning apples vector
}
void ProgrammLauncher::prepare()
{
    auto snake = std::make_unique<Snake>(get_snake_vector(), ColorsSettings::SNAKE); // parameters realisation for game
    auto apples = get_apples_vector();                                               // parameters realisation for game
    game = std::make_unique<Game>(std::move(snake), std::move(apples));              // creating the game
    menu = std::make_unique<Menu>();                                                 // creating the menu

    // creating the Window
    InitWindow(WindowSettings::WIDTH, WindowSettings::HEIGHT, WindowSettings::NAME.c_str());
    if (WindowSettings::CURSOR_ENABLED)
    {
        EnableCursor();
    }
    SetTargetFPS(GameSettings::FPS);
    // creating the Window
}
void ProgrammLauncher::launch_programm()
{
    GameState game_state = GameState::Menu; // GameState operator.
    bool game_result;                       // last game's result.
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(ControlSettings::EXIT))
        {
            break;
        }
        BeginDrawing();
        switch (game_state)
        {
        case GameState::Menu:
        {
            bool should_start_game = menu->user_wants_to_start_game(); // input and update
            if (!should_start_game)
            {
                // drawing
                menu->render_menu();
                break;
            }
            game_state = GameState::Game;
            break;
        }
        case GameState::Game:
        {
            game_result = game->start_game();
            game_state = GameState::Restart;
        }
        case GameState::Restart:
            menu->render_aftergame_menu(game_result);
            if (menu->user_wants_to_restart())
            {
                game_state = GameState::Game;
            }
        }
        EndDrawing();
    }
    CloseWindow();
}
