#ifndef SCENE_HPP
#define SCENE_HPP

#include <SFML/Graphics.hpp>

#include "../ResourceManager.hpp"
#include "../InputManager.hpp"

class Scene {

public:
  Scene(InputManager& input) : input(&input), paused(false) {};
  virtual ~Scene() {};

  virtual void update() = 0;

  virtual void start(ResourceManager& resources) = 0;
  virtual void stop() = 0;
  virtual void resume() { paused = false; };
  virtual void pause() { paused = true; };

  virtual void draw(sf::RenderWindow&) = 0;

  bool isPaused() const
  {
    return paused;
  }

protected:
  InputManager* input;

private:
  bool paused;

};

#endif
