#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "InputManager.h"
#include "Scene.h"
#include "ResourceManager.h"

class MenuScene : public Scene {

public:
  MenuScene(InputManager&);

  void start(ResourceManager&);
  void stop();
  void update();

  void draw(sf::RenderWindow&);

private:
  sf::Sprite playBtn;
  bool playBtnHover;

};

#endif
