#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "InputManager.hpp"
#include "SceneManager.hpp"

class Game {

public:
  Game();

  void loop();

private:
  sf::RenderWindow window;
  InputManager input;
  SceneManager scenes;

  void update();
  void draw();

};

#endif
