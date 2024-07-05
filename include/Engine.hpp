#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Game.hpp"
#include "Input.hpp"
#include "Renderer.hpp"

#include <memory>

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
