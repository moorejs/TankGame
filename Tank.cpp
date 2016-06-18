#include "Constants.hpp"
#include "Tank.hpp"

Tank::Tank()
  : Entity(Entities::Tank::BASE_VELOCITY),
    onGround(false)
{
}

void Tank::init(ResourceManager& resources)
{
  sprite.setTexture(resources.getTexture("assets/tileset.png"));
  start();
}

void Tank::start()
{
  sprite.setPosition(Window::WIDTH * 0.5f, Window::HEIGHT * 0.5f);
}

void Tank::update(InputManager& input)
{
  if (onGround)
    velocity.y = 0.f;
  else
    fall();

  sprite.move(velocity);
  velocity.x *= Entities::Tank::DECEL;
}

void Tank::fall()
{
  velocity.y += Entities::GRAVITY;
}

void Tank::jump()
{
  velocity.y = -Entities::Tank::BASE_JUMP_VELOCITY;
  onGround = false;
}

void Tank::moveLeft()
{
  velocity.x = -maxVelocity;
}

void Tank::moveRight()
{
  velocity.x = maxVelocity;
}
