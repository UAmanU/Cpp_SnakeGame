#pragma once

#include <raylib.h>

struct Object
{
    Color color;

    Object(const Vector2 &vector, Color color);
    ~Object() = default;
    void draw() const;
};