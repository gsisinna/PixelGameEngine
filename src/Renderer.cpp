#include "Renderer.hpp"
#include <iostream>

Renderer::Renderer() : window(nullptr), sdlRenderer(nullptr) {}

Renderer::~Renderer() {
    if (sdlRenderer) {
        SDL_DestroyRenderer(sdlRenderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
}

bool Renderer::Initialize() {
    window = SDL_CreateWindow("Pixel Game Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!sdlRenderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}

void Renderer::Clear() {
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sdlRenderer);
}

void Renderer::Present() {
    SDL_RenderPresent(sdlRenderer);
}

void Renderer::DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(sdlRenderer, r, g, b, a);
    SDL_RenderDrawPoint(sdlRenderer, x, y);
}
