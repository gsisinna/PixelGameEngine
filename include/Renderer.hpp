#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL2/include/SDL.h>

class Renderer {
public:
    Renderer();
    ~Renderer();

    bool Initialize();
    void Clear();
    void Present();
    void DrawPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

private:
    SDL_Window* window;
    SDL_Renderer* sdlRenderer;
};

#endif // RENDERER_HPP
