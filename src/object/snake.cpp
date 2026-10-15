#include "include/object/snake.h"

void Snake::move()
{
    for (Vector2 &coords : vector)
    {
        coords.x += delta_x;
        coords.y += delta_y;
    }
}