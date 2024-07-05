#include "Engine.hpp"
#include <SDL2/include/SDL.h>
#include <iostream>

Engine::Engine() : running(false) {}

Engine::~Engine() { Cleanup(); }

bool Engine::Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return false;
  }

  renderer = std::make_unique<Renderer>();
  if (!renderer->Initialize()) {
    return false;
  }

  input = std::make_unique<Input>();
  game = std::make_unique<Game>();
  game->Initialize();

  running = true;
  return true;
}

void Engine::Cleanup() { SDL_Quit(); }

void Engine::Run() {
  if (!Initialize()) {
    return;
  }

  while (running) {
    input->Update();
    if (input->IsQuit()) {
      running = false;
    }

    game->Update(*input);

    renderer->Clear();
    game->Render(*renderer);
    renderer->Present();
  }

  Cleanup();
}
