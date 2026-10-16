#include "include/object/snake.h"
#include "include/config/game_settings.h"
void Snake::move()
{
    if (delta_x == 0 && delta_y == 0)
        return;
    std::vector<Vector2> new_vector;
    new_vector.push_back({vector[0].x + delta_x * GameSettings::TILE_LENGTH, vector[0].y + delta_y * GameSettings::TILE_LENGTH});
    int current_length = vector.size();
    for (auto &coords : vector)
    {
        new_vector.push_back(coords);
    }
    new_vector.pop_back();
    vector = new_vector;
}