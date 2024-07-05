#include "Game.hpp"
#include "Collision.hpp"
#include "Physics.hpp"

// Define gravity constant
const float GRAVITY = 0.5f;

Game::Game()
    : x(320), y(240), velocityX(0), velocityY(0), physics(GRAVITY),
      sprite(nullptr) {}

Game::~Game() {
  if (sprite) {
    SDL_DestroyTexture(sprite);
  }
}

void Game::Initialize() { InitializeWalls(); }

void Game::InitializeWalls() {
  // Example walls
  walls.push_back({100, 300, 50, 200});
  walls.push_back({300, 200, 50, 200});
}

void Game::InitializeSprites(Renderer &renderer) {
  // Load sprite texture
  sprite = renderer.LoadTexture("path/to/sprite.png");
  if (!sprite) {
    std::cerr << "Failed to load sprite texture!" << std::endl;
  }
}

void Game::Update(Input &input) {
  // Example game logic: move the pixel around
  const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);

  // Update physics
  physics.Update(x, y, velocityX, velocityY);

  // Check for keyboard input to control the object
  if (currentKeyStates[SDL_SCANCODE_UP]) {
    velocityY = -10; // Jump
  }
  if (currentKeyStates[SDL_SCANCODE_DOWN]) {
    y++; // Move down faster
  }
  if (currentKeyStates[SDL_SCANCODE_LEFT]) {
    velocityX = -5; // Move left
  }
  if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
    velocityX = 5; // Move right
  }

  // Simple collision detection with walls
  for (auto &wall : walls) {
    if (x > wall.x && x < wall.x + wall.width && y > wall.y &&
        y < wall.y + wall.height) {
      // Handle collision
      if (velocityX > 0)
        x = wall.x - 1; // Hit from the left
      if (velocityX < 0)
        x = wall.x + wall.width + 1; // Hit from the right
      if (velocityY > 0)
        y = wall.y - 1; // Hit from above
      if (velocityY < 0)
        y = wall.y + wall.height + 1; // Hit from below
      velocityX = 0;
      velocityY = 0;
    }
  }
}

void Game::Render(Renderer &renderer) {
  // Clear screen
  renderer.Clear();

  // Draw walls
  for (const auto &wall : walls) {
    renderer.DrawRectangle(wall.x, wall.y, wall.width, wall.height, 255, 255,
                           255, 255);
  }

  // Draw sprite
  if (sprite) {
    renderer.DrawTexture(sprite, static_cast<int>(x), static_cast<int>(y), 32,
                         32); // Draw sprite at (x, y)
  } else {
    // Fallback to drawing a pixel if sprite is not available
    renderer.DrawPixel(static_cast<int>(x), static_cast<int>(y), 255, 0, 0,
                       255);
  }

  // Present the rendered frame
  renderer.Present();
}
