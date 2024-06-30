#include "Input.hpp"

void Input::Update() {
    SDL_Event e;
    quit = false;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            quit = true;
        }
    }
}

bool Input::IsQuit() const {
    return quit;
}
