#include "include/object/snake.h"         //including the snake struct's declaration
#include "include/config/game_settings.h" //including the GameSettings namespace for evaluating the snake's new position.
void Snake::move()
{
    if (delta_x == 0 && delta_y == 0) // checking if snake needs to move
        return;
    std::vector<Vector2> new_vector;
    Vector2 future_head = {vector[0].x + delta_x * GameSettings::TILE_LENGTH, vector[0].y + delta_y * GameSettings::TILE_LENGTH};
    new_vector.push_back(future_head); // pushing back the head coordinates to the new_vector depending on delta_x and delta_y
    for (auto &coords : vector)
    {
        new_vector.push_back(coords); // pushing back the current vector attribute elements to the new_vector with the new head
    }

    new_vector.pop_back(); // Deleting the edge of snake.
    vector = new_vector;   // assigning the vector variable for new_vector with updated position.
}