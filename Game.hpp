#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

#include "InputManager.hpp"
#include "SceneManager.hpp"

class Game {

public:
  Game(sf::RenderWindow& window);
  ~Game();

  void update();
  void draw();

private:
  sf::RenderWindow* window;
  InputManager input;
  SceneManager scenes;

};

#endif
