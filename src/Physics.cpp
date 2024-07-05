#include "Physics.hpp"
#include "Collision.hpp"

// Constructor
Physics::Physics(float gravity) : gravity(gravity) {}

// Update physics for an object
void Physics::Update(float &x, float &y, float &velocityX, float &velocityY) {
  // Apply gravity to the vertical velocity
  velocityY += gravity;

  // Update position based on velocity
  x += velocityX;
  y += velocityY;

  // Simple collision with the ground (assuming ground level is at y = 480)
  Collision::CheckGroundCollision(y, velocityY, 480);

  // Simple collision with the left and right walls (assuming window width is
  // 640)
  Collision::CheckWallCollision(x, velocityX, 0, 640);
}
