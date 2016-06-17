#ifndef MENUSCENE_HPP
#define MENUSCENE_HPP

#include <utility>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Scene.hpp"
#include "../InputManager.hpp"
#include "../ResourceManager.hpp"

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
