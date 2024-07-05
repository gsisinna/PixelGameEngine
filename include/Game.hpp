#ifndef GAME_HPP
#define GAME_HPP

#include "Input.hpp"
#include "Physics.hpp"
#include "Renderer.hpp"

#include <SDL2/SDL.h>

#include <iostream>
#include <vector>

class Game {
public:
  Game();
  ~Game();

  void Initialize();
  void Update(Input &input);
  void Render(Renderer &renderer);

private:
  float x, y;
  float velocityX, velocityY;
  Physics physics; // Physics object

  // Walls
  struct Wall {
    int x, y, width, height;
  };
  std::vector<Wall> walls;

  // Sprites
  SDL_Texture *sprite;

  void InitializeWalls();
  void InitializeSprites(Renderer &renderer);
};

#endif // GAME_HPP
