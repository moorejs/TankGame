#include "Constants.hpp"
#include "Game.hpp"
#include "scenes/GameScene.hpp"
#include "scenes/MenuScene.hpp"

Game::Game()
  : window(sf::VideoMode(Window::WIDTH, Window::HEIGHT), "Game Window"),
    input(window), scenes()
{

  input.bind("left click", sf::Mouse::Left);
  input.bind("left", sf::Keyboard::A);
  input.bind("right", sf::Keyboard::D);
  input.bind("jump", sf::Keyboard::W);

  scenes.pushScene<GameScene>(input);

  scenes.togglePause();

  scenes.togglePause();
}

void Game::loop()
{
  while (window.isOpen()) {

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
}

void Game::draw()
{
  window.clear();

  scenes.drawScene(window);

  window.display();
}


