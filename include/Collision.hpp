#ifndef COLLISION_HPP
#define COLLISION_HPP

class Collision {
public:
  // Check collision with the ground
  static bool CheckGroundCollision(float &y, float &velocityY,
                                   float groundLevel);

  // Check collision with walls
  static bool CheckWallCollision(float &x, float &velocityX, float leftWall,
                                 float rightWall);
};

#endif // COLLISION_HPP
