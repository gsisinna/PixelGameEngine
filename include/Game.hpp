#ifndef GAME_HPP
#define GAME_HPP

#include "Renderer.hpp"
#include "Input.hpp"

class Game {
public:
    Game();
    ~Game();

    void Initialize();
    void Update(Input& input);
    void Render(Renderer& renderer);

private:
    int x, y;
};

#endif // GAME_HPP
