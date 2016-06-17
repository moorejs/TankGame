#include <iostream>

#include "MenuScene.hpp"

MenuScene::MenuScene(InputManager& input)
  : Scene(input), playBtn()
{
}

void MenuScene::start(ResourceManager& resources)
{
  playBtn.setTexture(resources.getTexture("button_tileset.png"));
  playBtn.setTextureRect({0, 0, 100, 50});
  playBtn.setPosition(300, 300);
}

void MenuScene::stop()
{
  
}

void MenuScene::update()
{
  playBtnHover =
    playBtn.getGlobalBounds().contains((float)input->getMousePosition().x,
                                       (float)input->getMousePosition().y);

  /* horrible button example, sets texture rect every frame lol */
  if (playBtnHover) {
    if (input->triggered("left click")) {
      std::cout << "Looks like I'll have to push the scene manager into scenes to control pushing/popping from within a scene..." << std::endl;
    }
    playBtn.setTextureRect({0, 50, 100, 50});
  } else {
    playBtn.setTextureRect({0, 0, 100, 50});
  }
}

void MenuScene::draw(sf::RenderWindow& window)
{
  window.draw(playBtn);
}
