#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Camera
{
    public:
        void centerOnEntity(const Entity& entity);
        void draw(Entity& entity, sf::RenderWindow& window) const;
    private:
        sf::Vector2f m_position;
};