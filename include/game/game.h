#pragma once

#include "game_renderer.h" //including the GameRenderer class for rendering the Window

#include <memory> //including STL memory for the smart pointer to snake which is owned by Game class

/*In this file, there's a Game class declaration.
Game class owns snake smart pointer, GameRenderer object for rendering and apples vector.
Game class launches the main loop.*/

class Game
{
private:
    GameRenderer renderer;               // GameRenderer attribute for rendering
    std::unique_ptr<Snake> snake;        // unique_ptr to Snake object
    std::vector<Apple> apples;           // vector of Apple-type objects
    bool check_snake_validality() const; // checks if snake's head is out of field.

    int score = 0;          // integer attribute that shows how many scores does user has

public:
    Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples); // constructor that takes smart pointer to snake ans vector of Apple-type objects
    ~Game() = default;                                             // default constructor

    bool game_should_continue() const; //returns true if game should continue
    bool check_win() const; // returns true if user has enough score to win
    void update(); // updates the snake, apples.
    void draw();   // calls render methods to draw in Window
};