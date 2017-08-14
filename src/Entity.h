#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

class Entity
{
    public:
        Entity(int id);
        Entity(EntityState& entityState);
        EntityState getState();
        void setState(EntityState& entityState);

        void update();

        unsigned short m_id;
        sf::Vector2f m_position;
        sf::Vector2f m_velocity;
    private:
};