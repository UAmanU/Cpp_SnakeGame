#pragma once

#include "lib/raylib.h" //including the lib for Vector2 type and Color enum
#include <vector>       //including STL Vector for Object::vector<Vector2> attribute

/*In this file, there's a declaration pf Object struct.
struct Object is an small interface for Snake and Apple structs.
It has Color and vector<Vector2> with its coordinates.*/

struct Object
{
    Color color;                 // color attribute
    std::vector<Vector2> vector; // vector of its coordinates

    Object(std::vector<Vector2> vector, Color color); // constructor
    ~Object() = default;                              // default destructor
};