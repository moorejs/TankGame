#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include "Scene.hpp"
#include "../InputManager.hpp"
#include "../ResourceManager.hpp"

class GameScene : public Scene {

public:
  GameScene(InputManager&);

  void start(ResourceManager&);
  void stop();
  void resume();
  void pause();
  void update();

  void draw(sf::RenderWindow&);

};

#endif
