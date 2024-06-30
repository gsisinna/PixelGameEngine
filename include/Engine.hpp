#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <memory>
#include "Renderer.hpp"
#include "Input.hpp"
#include "Game.hpp"

class Engine {
public:
    Engine();
    ~Engine();

    void Run();

private:
    bool Initialize();
    void Cleanup();

    std::unique_ptr<Renderer> renderer;
    std::unique_ptr<Input> input;
    std::unique_ptr<Game> game;

    bool running;
};

#endif // ENGINE_HPP
