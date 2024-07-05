#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>

class Renderer {
public:
  Renderer();
  ~Renderer();

  bool Initialize();
  void Clear();
  void Present();
  void DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  void DrawRectangle(int x, int y, int width, int height, Uint8 r, Uint8 g,
                     Uint8 b, Uint8 a);
  void DrawTexture(SDL_Texture *texture, int x, int y, int width, int height);
  SDL_Texture *LoadTexture(const std::string &file);

private:
  SDL_Window *window;
  SDL_Renderer *sdlRenderer;
};

#endif // RENDERER_HPP
