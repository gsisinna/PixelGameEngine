#ifndef PHYSICS_HPP
#define PHYSICS_HPP

class Physics {
public:
  // Constructor
  Physics(float gravity);

  // Update physics for an object
  void Update(float &x, float &y, float &velocityX, float &velocityY);

private:
  float gravity;
};

#endif // PHYSICS_HPP
