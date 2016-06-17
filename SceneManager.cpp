#include "SceneManager.hpp"

void SceneManager::updateScene()
{
  if (!scenes.empty())
    scenes.top()->update();
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
