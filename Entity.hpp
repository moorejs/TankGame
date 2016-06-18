#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>

#include "InputManager.hpp"
#include "ResourceManager.hpp"

class Entity : public sf::Drawable
{

public:
  Entity(float maxVelocity)
    : active(true),
      sprite(),
      maxVelocity(maxVelocity), /* this should be removed */
      velocity(0.f, 0.f)
  {};

  virtual void init(ResourceManager&) = 0;
  virtual void start() = 0;
  virtual void update(InputManager&) = 0;

  sf::FloatRect getBounds() const
  {
    return sprite.getGlobalBounds();
  };

protected:
  bool active;

  sf::Sprite sprite;
  float maxVelocity;
  sf::Vector2f velocity;

private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
  {
    if (active)
      target.draw(sprite, states);
  };

};

#endif
