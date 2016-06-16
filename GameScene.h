#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "InputManager.h"
#include "Scene.h"
#include "ResourceManager.h"

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
