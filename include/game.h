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

public:
    Game(std::unique_ptr<Snake> snake, std::vector<Apple> apples);
    ~Game() = default;
    void start_game();
};