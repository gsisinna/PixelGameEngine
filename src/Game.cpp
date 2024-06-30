#include "Game.hpp"

Game::Game() : x(320), y(240) {}

Game::~Game() {}

void Game::Initialize() {}

void Game::Update(Input& input) {
    // Example game logic: move the pixel around
    const Uint8* currentKeyStates = SDL_GetKeyboardState(nullptr);
    if (currentKeyStates[SDL_SCANCODE_UP]) {
        y--;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        y++;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        x--;
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        x++;
    }
}

void Game::Render(Renderer& renderer) {
    renderer.DrawPixel(x, y, 255, 0, 0, 255);
}
