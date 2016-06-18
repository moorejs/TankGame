#ifndef MISSILE_HPP
#define MISSILE_HPP

#include "Entity.hpp"
#include "InputManager.hpp"
#include "ResourceManager.hpp"

class Missile : public Entity
{

public:
  Missile();

  void init(ResourceManager&);
  void start();
  void update(InputManager&);

  void drop(float x, float y);

};

#endif
