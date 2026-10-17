#include "include/object/object.h" //including the struct Object declaration

Object::Object(std::vector<Vector2> vector, Color color) : vector(std::move(vector)), color(color) {}; // realisation of Object struct's constructor.
