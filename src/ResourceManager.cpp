#include "ResourceManager.h"

#include "Logger.h"

const std::string assetFilePath = "assets/";

std::map<std::string, sf::Texture> ResourceManager::s_textures;

sf::Texture ResourceManager::getTexture(std::string file)
{
    auto it = s_textures.find(file);
    if (it != s_textures.end()) {
        return it->second;
    }
    sf::Texture texture;
    std::string filename = assetFilePath + file;
    if (!texture.loadFromFile(filename)) {
        Logger::log("Missing asset: " + filename);
    } else {
        Logger::log("Loading texture: " + filename);
        s_textures.insert({file, texture});
    }
    return texture;
};