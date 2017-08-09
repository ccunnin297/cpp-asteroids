#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

class ClientGame
{
    public:
        ClientGame();
        void draw(sf::RenderWindow &window);
    private:
        std::vector<std::unique_ptr<Entity>> m_entities;
};