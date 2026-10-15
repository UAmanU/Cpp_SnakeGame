#pragma once

#include "object.h"
#include <vector>

struct Snake : Object
{
    std::vector<Vector2> vector;
    Color color;
    Snake();
    Snake(std::vector<Vector2> vector, Color color);
    ~Snake() = default;
    void draw();
    void move(int delta_x, int delta_y);
};
