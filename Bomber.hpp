#ifndef BOMBER_HPP
#define BOMBER_HPP

#include "Entity.hpp"
#include "InputManager.hpp"
#include "ResourceManager.hpp"

class Bomber : public Entity
{

public:
  Bomber();

  void init(ResourceManager&);
  void start();
  void update(InputManager&);

};

#endif
