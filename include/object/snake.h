#pragma once

#include "object.h" //including the Object struct interface

/*In this file,There's a declaration of Object's child struct Snake.
Snake can move and eat apples.
Each eaten apple makes snake's size bigger by one block*/

struct Snake : Object
{
    using Object::Object; // Snake doesn't has any constructors except Object one.

    int delta_x = 0; // delta_x integer shows the snake's direction for X .  0 - nowhere , 1 - right , -1 - left.
    int delta_y = 0; // delta_y integer shows the snake's direction for Y. 0 - nowhere, 1 - down, 1 - up.

    ~Snake() = default; // default destructor

    void move(); // move method
};
