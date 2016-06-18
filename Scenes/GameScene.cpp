#include <iostream>

#include "../Constants.hpp"
#include "GameScene.hpp"

GameScene::GameScene(InputManager& input)
  : Scene(input), player(), ground(), bombers(5)
{
}

void GameScene::start(ResourceManager& resources)
{
  std::cout << "Initializing game scene" << std::endl;
  player.init(resources);
  for (auto& bomber : bombers) {
    bomber.init(resources);
  }

  ground.setTexture(resources.getTexture("assets/ground.png"));
  ground.setPosition(0.f, 720.f-200.f);
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
  /* collision is naive, design is bad for entities right now */
  if (input->triggered("left"))
    player.moveLeft();
  if (input->triggered("right"))
    player.moveRight();
  if (input->triggered("jump")) {
    player.jump();
    player.onGround = false;
  }

  player.update(*input);
  bombers.at(0).update(*input);

  if (!player.onGround && ground.getGlobalBounds().intersects(player.getBounds())) {
    player.onGround = true;
  }

  /* proof of concept here */
  std::cout << RNG::getRandomNumber(0, 10) << std::endl;
  std::cout << RNG::getRandomNumber(0.f, 1.f) << std::endl;
}

void GameScene::draw(sf::RenderWindow& window)
{
  window.draw(player);
  for (const auto& bomber : bombers) {
    window.draw(bomber);
  }

  window.draw(ground);
}
