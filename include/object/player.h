#pragma once

#include "object.h"

struct Player : Object
{
    Camera3D camera;
    Player(Vector3 vector, Color color, Camera3D camera);
    ~Player() = default;
    void draw() const;
};