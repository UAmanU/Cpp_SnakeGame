#pragma once

#include "include/object/object.h" //including the object struct interface

/*In this file,There's a declaration of Object's child struct Apple.
Apple can move and has only one coordinate.
Apple moves only when it was eaten by Snake */

struct Apple : Object
{
    Apple(Vector2 coords, Color color); // constructor
    void move();                        // move method that changes its coordinates to random ones
};