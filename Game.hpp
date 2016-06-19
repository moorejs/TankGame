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

  sf::Clock fpsClock;
  float currentFrameTime, lastFrameTime;
  float totalFrameTime;
  unsigned frameCounter;

  void update();
  void draw();

};

#endif
