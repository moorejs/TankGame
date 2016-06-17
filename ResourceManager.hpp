#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <initializer_list>
#include <string>
#include <unordered_map>

#include <SFML/Graphics.hpp>

class ResourceManager {

public:
  ResourceManager();

  /* loads texture by file if not already loaded and returns a reference to it */
  sf::Texture& getTexture(const std::string& filename);

  /* getTexture will load for you, only use .hppis if bulk loading in advance is needed */
  void loadTextures(std::initializer_list<std::string> filenamesToLoad);

private:
  std::unordered_map<std::string, sf::Texture> textures;

  /* private as it .hppould rarely be used, in favor of getTexture */
  void loadTexture(const std::string& filename);
};

#endif
