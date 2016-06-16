#include "ResourceManager.h"

ResourceManager::ResourceManager()
  : textures()
{
}

sf::Texture& ResourceManager::getTexture(const std::string& filename)
{
  if (textures.find(filename) == textures.end()) { /* texture not loaded yet */
    loadTexture(filename);
  }

  return textures[filename];
}

void ResourceManager::loadTexture(const std::string& filename)
{
  sf::Texture newTexture;
  if (!newTexture.loadFromFile(filename)) {
    /* report error */
  }
  textures[filename] = newTexture;
}

/* useful when the user want to do bulk loading of textures (e.g. during loading screen) */
void ResourceManager::loadTextures(std::initializer_list<std::string> filenamesToLoad)
{
  for (auto const& filename : filenamesToLoad) {
    loadTexture(filename);
  }
}
