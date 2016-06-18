#ifndef GAMESCENE_HPP
#define GAMESCENE_HPP

#include <vector>

#include "Scene.hpp"
#include "../InputManager.hpp"
#include "../ResourceManager.hpp"
#include "../Tank.hpp"
#include "../Bomber.hpp"

class GameScene : public Scene {

public:
  GameScene(InputManager&);

  void start(ResourceManager&);
  void stop();
  void resume();
  void pause();
  void update();

  void draw(sf::RenderWindow&);

private:
  Tank player;
  sf::Sprite ground;
  std::vector<Bomber> bombers;

};

#endif
