#pragma once

#include "include/object/object.h"

struct Apple : Object
{
    Apple(Vector2 coords, Color color);
    void move();
};