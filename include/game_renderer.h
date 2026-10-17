#pragma once

#include "include/object/snake.h" // For rendering snake in window.
#include "include/object/apple.h" // For rendering apples in window.
#include <vector>                 // For GameRenderer::draw_apples(vector<Apple>&apples) method that will take vector of apples and draw them.

/*GameRenderer is a class for rendering snake, apples and etc. in window.
It doesn't own anything so constructors and destructors are default and methods are constant*/

class GameRenderer
{
private:
    void draw_apple(const Apple &apple) const; // This method will render 1 apple.
public:
    GameRenderer() = default; // constructor and destructor are default because GameRenderer doesn't need to own snake and apples.
    ~GameRenderer() = default;
    void draw_all_apples(const std::vector<Apple> &apples) const; // This method calls GameRenderer::draw_apple(const Apple &apple) const for each apple in vector
    void draw_snake(const Snake &snake) const;                    // This method draws rectangle for each x,y from snake.vector in window
    void draw_field() const;                                      // GameRenderer::draw_field() calls ClearBackground() and draws lines for tile separating.
};