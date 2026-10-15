#pragma once

#include <raylib.h>
#include <vector>

struct Object
{
    Color color;
    std::vector<Vector2> vector;

    Object(std::vector<Vector2> vector, Color color);
    ~Object() = default;
};