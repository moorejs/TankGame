#include "InputManager.h"

InputManager::InputManager(sf::RenderWindow& window)
  : window(&window), keyboard(), mouse()
{
}

void InputManager::bind(const std::string& action, sf::Keyboard::Key key)
{
  if (keyboard.find(action) == keyboard.end())
    keyboard[action] = key;
  else {
    /* already bound */
  }
}

void InputManager::bind(const std::string& action, sf::Mouse::Button button)
{
  if (mouse.find(action) == mouse.end())
    mouse[action] = button;
  else {
    /* already bound */
  }
}

bool InputManager::triggered(const std::string& action)
{
  if (keyboard.find(action) != keyboard.end())
    return sf::Keyboard::isKeyPressed(keyboard[action]);

  if (mouse.find(action) != mouse.end())
    return sf::Mouse::isButtonPressed(mouse[action]);

  /* error */
  return false;
}

sf::Vector2i InputManager::getMousePosition() const
{
  return sf::Mouse::getPosition(*window);
}
