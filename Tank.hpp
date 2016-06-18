#ifndef TANK_HPP
#define TANK_HPP

#include "Entity.hpp"
#include "InputManager.hpp"
#include "ResourceManager.hpp"

class Tank : public Entity
{

public:
  Tank();

  void init(ResourceManager&);
  void start();
  void update(InputManager&);

  void fall();
  void jump();
  void moveLeft();
  void moveRight();

  bool onGround;
};

#endif
