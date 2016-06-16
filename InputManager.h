#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

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

  /* inefficient method for checking if action is triggered */
  bool triggered(const std::string& action);

  sf::Vector2i getMousePosition() const;

private:
  sf::Window* window;
  std::unordered_map<std::string, sf::Keyboard::Key> keyboard;
  std::unordered_map<std::string, sf::Mouse::Button> mouse;
};

#endif
