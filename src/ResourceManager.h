#pragma once

#include <SFML/Graphics.hpp>

class ResourceManager
{
    public:
        static const sf::Texture& getTexture(std::string path);
    private:
        static std::map<std::string, sf::Texture> s_textures;
};