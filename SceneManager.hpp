#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <memory>
#include <stack>

#include <SFML/Graphics.hpp>

#include "Scenes/Scene.hpp"
#include "ResourceManager.hpp"

class SceneManager {

public:
  void updateScene();
  void drawScene(sf::RenderWindow& window);

  template <typename T, typename ... Args>
  void pushScene(Args&&... args)
  {
    scenes.push(std::make_unique<T>(std::forward<Args>(args)...));
    scenes.top()->start(resources);
  };
  void popScene();

  void togglePause();

private:
  ResourceManager resources;
  std::stack<std::unique_ptr<Scene>> scenes;

};

#endif
