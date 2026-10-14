#pragma once

#include <raylib.h>

struct Object
{
    Vector3 vector;
    Color color;

    Object(const Vector3 &vector, Color color);
    ~Object() = default;
    void draw() const;
};