#include <iostream>

#include "GameScene.hpp"

GameScene::GameScene(InputManager& input)
  : Scene(input)
{
}

void GameScene::start(ResourceManager& resources)
{
  std::cout << "Initializing game scene" << std::endl;
  player.setTexture(resources.getTexture("tileset.png"));
  player.setPosition(1000, 60);
}

void GameScene::stop()
{
  std::cout << "Ending game scene" << std::endl;
}

void GameScene::resume()
{
  Scene::resume();
  std::cout << "Resuming game scene" << std::endl;
}

void GameScene::pause()
{
  Scene::pause();
  std::cout << "Pausing game scene" << std::endl;
}

void GameScene::update()
{
  if (input->triggered("left"))
    player.move(-1.f, 0.f);
}

void GameScene::draw(sf::RenderWindow& window)
{
  window.draw(player);
}
