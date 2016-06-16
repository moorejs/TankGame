#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "InputManager.h"
#include "SceneManager.h"

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
