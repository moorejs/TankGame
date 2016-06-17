#include "SceneManager.hpp"

void SceneManager::updateScene()
{
  if (!scenes.empty()) {
    scenes.top()->update();

    /* Check if we have a new scene to launch */
    if (scenes.top()->sceneToPush != nullptr) {
      scenes.push(std::move(scenes.top()->sceneToPush));
      scenes.top()->start(resources);
    }
  }
}

void SceneManager::drawScene(sf::RenderWindow& window)
{
  if (!scenes.empty())
    scenes.top()->draw(window);
}

void SceneManager::popScene()
{
  scenes.top()->stop();
  scenes.pop();
}

void SceneManager::togglePause()
{
  if (scenes.top()->isPaused())
    scenes.top()->resume();
  else
    scenes.top()->pause();
}
