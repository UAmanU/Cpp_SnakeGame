#pragma once

#include "object\snake.h"
#include "object\apple.h"

#include <memory>

class Game
{
private:
    std::unique_ptr<Snake> snake;
    std::vector<Apple> apples;
    void prepare();
    void update_snake_position();
    bool check_snake_validality() const;
    bool check_exit();
    void draw_apples() const;

public:
    Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples);
    ~Game() = default;
    void start_game();
};