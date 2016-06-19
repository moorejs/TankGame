#include <iostream>

#include "Constants.hpp"
#include "Game.hpp"
#include "scenes/GameScene.hpp"
#include "scenes/MenuScene.hpp"

Game::Game()
  : window(sf::VideoMode(Window::WIDTH, Window::HEIGHT), "Game Window"),
    input(window), scenes(),
    fpsClock(), currentFrameTime(0.f), lastFrameTime(0.f),
    totalFrameTime(0.f), frameCounter(0)
{

  input.bind("left click", sf::Mouse::Left);
  input.bind("left", sf::Keyboard::A);
  input.bind("right", sf::Keyboard::D);
  input.bind("jump", sf::Keyboard::W);

  scenes.pushScene<GameScene>(input);

  /* just a test */
  scenes.togglePause();
  scenes.togglePause();
}

void Game::loop()
{
  while (window.isOpen()) {
    ++frameCounter;

    /* should be its own function */
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    update();
    draw();
  }
}

void Game::update()
{
  scenes.updateScene();

  currentFrameTime = fpsClock.restart().asSeconds();
  lastFrameTime = currentFrameTime;
  totalFrameTime += currentFrameTime;
  if (frameCounter % 200 == 0) {
    std::cout << 1.f / (totalFrameTime / 200) << std::endl;
    totalFrameTime = 0;
  }
}

void Game::draw()
{
  window.clear();

  scenes.drawScene(window);

  window.display();
}


