#include "include/game.h"

#include <memory>

int main()
{
    // Code
    std::unique_ptr<Game> game = std::make_unique<Game>();
    game->start_game();
    // Code

    return 0;
}