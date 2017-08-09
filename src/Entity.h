#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
    public:
        Entity(unsigned short id);

        unsigned short m_id;
        sf::Vector2f m_position;
    private:
};