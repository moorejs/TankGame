#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class InputManager {

  /* missing mouse wheel support, joystick support, just rudimentary.
   * not very happy with the functionality of this class.
   */

public:
  InputManager(sf::RenderWindow& window);

  void bind(const std::string& action, sf::Keyboard::Key key);
  void bind(const std::string& action, sf::Mouse::Button button);

  /* way to check if action is triggered (inefficient) */
  bool triggered(const std::string& action);

  sf::Vector2i getMousePosition() const;

private:
  sf::Window* window;
  std::unordered_map<std::string, sf::Keyboard::Key> keyboard;
  std::unordered_map<std::string, sf::Mouse::Button> mouse;
};

#endif
