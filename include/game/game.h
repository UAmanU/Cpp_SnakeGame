#pragma once

#include "game_renderer.h"
#include "object\snake.h"
#include "object\apple.h"

#include <memory>

class Game
{
private:
    GameRenderer renderer;
    std::unique_ptr<Snake> snake;
    std::vector<Apple> apples;
    void update_snake();
    bool check_snake_validality() const;
    bool check_exit();

    bool check_win() const;
    int score = 0;

public:
    Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples);
    ~Game() = default;
    void prepare();
    void start_game();
};