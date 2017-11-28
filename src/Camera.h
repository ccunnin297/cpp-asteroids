#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"

class Camera
{
    public:
        void centerOnEntity(const Entity& entity);
        sf::View getView();
    private:
        sf::Vector2f m_position;
};