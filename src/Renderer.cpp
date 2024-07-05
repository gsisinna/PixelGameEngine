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
  IMG_Quit();
  SDL_Quit();
}

bool Renderer::Initialize() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return false;
  }

  if (!IMG_Init(IMG_INIT_PNG)) {
    std::cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError()
              << std::endl;
    return false;
  }

  window =
      SDL_CreateWindow("Pixel Game Engine", SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
  if (!window) {
    std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    return false;
  }

  sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (!sdlRenderer) {
    std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError()
              << std::endl;
    return false;
  }

  return true;
}

void Renderer::Clear() {
  SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
  SDL_RenderClear(sdlRenderer);
}

void Renderer::Present() { SDL_RenderPresent(sdlRenderer); }

void Renderer::DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
  SDL_SetRenderDrawColor(sdlRenderer, r, g, b, a);
  SDL_RenderDrawPoint(sdlRenderer, x, y);
}

void Renderer::DrawRectangle(int x, int y, int width, int height, Uint8 r,
                             Uint8 g, Uint8 b, Uint8 a) {
  SDL_Rect rect = {x, y, width, height};
  SDL_SetRenderDrawColor(sdlRenderer, r, g, b, a);
  SDL_RenderFillRect(sdlRenderer, &rect);
}

void Renderer::DrawTexture(SDL_Texture *texture, int x, int y, int width,
                           int height) {
  SDL_Rect dstRect = {x, y, width, height};
  SDL_RenderCopy(sdlRenderer, texture, nullptr, &dstRect);
}

SDL_Texture *Renderer::LoadTexture(const std::string &file) {
  SDL_Surface *loadedSurface = IMG_Load(file.c_str());
  if (!loadedSurface) {
    std::cerr << "Unable to load image " << file
              << "! SDL_image Error: " << IMG_GetError() << std::endl;
    return nullptr;
  }
  SDL_Texture *newTexture =
      SDL_CreateTextureFromSurface(sdlRenderer, loadedSurface);
  SDL_FreeSurface(loadedSurface);
  if (!newTexture) {
    std::cerr << "Unable to create texture from " << file
              << "! SDL Error: " << SDL_GetError() << std::endl;
  }
  return newTexture;
}
