#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

class Entity
{
    public:
        Entity(unsigned short id);
        Entity(EntityState& entityState);
        EntityState getState();
        void setState(EntityState& entityState);

        void update();
        virtual void draw(sf::RenderWindow& window);

        unsigned short m_id;
        sf::Vector2f m_position;
        sf::Vector2f m_velocity;
        int m_rotation;
    private:
};