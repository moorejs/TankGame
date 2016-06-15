#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <initializer_list>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class ResourceManager {

public:
  ResourceManager();
  ~ResourceManager();

  /* loads texture by file if not already loaded and returns a reference to it */
  sf::Texture& getTexture(const std::string& filename);

  /* getTexture will load for you, only use this if bulk loading in advance is needed */
  void loadTextures(std::initializer_list<std::string> filenamesToLoad);

private:
  std::unordered_map<std::string, sf::Texture> textures;

  /* private as it should rarely be used, in favor of getTexture */
  void loadTexture(const std::string& filename);
};

#endif
