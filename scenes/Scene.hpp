#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>

#include <SFML/Graphics.hpp>

#include "../InputManager.hpp"
#include "../ResourceManager.hpp"

class Scene {

public:
  Scene(InputManager& input)
    : sceneToPush(nullptr), input(&input), paused(false)
  {};
  virtual ~Scene() {};

  virtual void update() = 0;

  virtual void start(ResourceManager&) = 0;
  virtual void stop() = 0;
  virtual void resume() { paused = false; };
  virtual void pause() { paused = true; };

  virtual void draw(sf::RenderWindow&) = 0;

  bool isPaused() const
  {
    return paused;
  }

  std::unique_ptr<Scene> sceneToPush;

protected:
  InputManager* input;

private:
  bool paused;
};

#endif
