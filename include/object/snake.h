#pragma once

#include "object.h"
#include <vector>

struct Snake : Object
{
    int delta_x = 0;
    int delta_y = 0;

    ~Snake() = default;

    void move();
};
