#include "include/object/object.h"

Object::Object(std::vector<Vector2> vector, Color color) : vector(std::move(vector)), color(color) {};
