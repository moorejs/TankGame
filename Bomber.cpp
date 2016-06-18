#include "Constants.hpp"
#include "Bomber.hpp"

Bomber::Bomber()
  : Entity(Entities::Bomber::BASE_VELOCITY)
{
}

void Bomber::init(ResourceManager& resources)
{
  sprite.setTexture(resources.getTexture("assets/tileset.png"));
  start();
}

void Bomber::start()
{
  sprite.setPosition(-getBounds().width, Window::HEIGHT * RNG::getRandomNumber(0.2f, 0.95f));
  velocity.x = maxVelocity;
}

void Bomber::update(InputManager& input)
{
  /* velocity.y should be a sin function */
  sprite.move(velocity);
}
