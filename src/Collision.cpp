#include "Collision.hpp"

// Check collision with the ground
bool Collision::CheckGroundCollision(float &y, float &velocityY,
                                     float groundLevel) {
  if (y > groundLevel) {
    y = groundLevel;
    velocityY = 0;
    return true;
  }
  return false;
}

// Check collision with walls
bool Collision::CheckWallCollision(float &x, float &velocityX, float leftWall,
                                   float rightWall) {
  bool collided = false;
  if (x < leftWall) {
    x = leftWall;
    velocityX = 0;
    collided = true;
  }
  if (x > rightWall) {
    x = rightWall;
    velocityX = 0;
    collided = true;
  }
  return collided;
}
