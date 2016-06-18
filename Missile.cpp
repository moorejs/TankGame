#include "Constants.hpp"
#include "Missile.hpp"

Missile::Missile()
  : Entity(9999 /* this needs to be reworked... */)
{
}

void Missile::init(ResourceManager& resources)
{
  sprite.setTexture(resources.getTexture("assets/tileset.png"));
  sprite.setTextureRect({0, 0, 5, 20});
}

void Missile::start()
{
}

void Missile::update(InputManager& input)
{

  sprite.move(velocity);
}
