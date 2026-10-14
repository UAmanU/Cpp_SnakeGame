#pragma once

#include <vector>
#include "object\object.h"

class Game
{
private:
    std::vector<Object> objects;

public:
    Game(std::vector<Object> objects);
    ~Game() = default;
    void start_game();
};