#include <iostream>

#include "GameScene.hpp"

GameScene::GameScene(InputManager& input)
  : Scene(input)
{
}

void GameScene::start(ResourceManager& resources)
{
  std::cout << "Initializing scene" << std::endl;
  resources.loadTextures({"tileset.png", "cute_image.jpg"});
  std::cout << "Done initializing" << std::endl;
}

void GameScene::stop()
{
  std::cout << "Ending scene" << std::endl;
}

void GameScene::resume()
{
  Scene::resume();
  std::cout << "Resuming scene" << std::endl;
}

void GameScene::pause()
{
  Scene::pause();
  std::cout << "Pausing scene" << std::endl;
}

void GameScene::update()
{
  if (input->triggered("left"))
    std::cout << "updating" << std::endl;

  if (input->triggered("left click"))
    std::cout << "left click" << std::endl;
}

void GameScene::draw(sf::RenderWindow& window)
{
  
}
