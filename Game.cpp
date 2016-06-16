#include <iostream>

#include "Game.h"
#include "MenuScene.h"
#include "GameScene.h"

Game::Game(sf::RenderWindow& window)
  : window(&window), input(window), scenes()
{
  input.bind("left click", sf::Mouse::Left);
  input.bind("left", sf::Keyboard::A);

  scenes.pushScene<MenuScene>(input);

  scenes.togglePause();

  scenes.togglePause();
}

Game::~Game()
{
  
}

void Game::update()
{
  scenes.updateScene();
}

void Game::draw()
{
  scenes.drawScene(*window);
}


