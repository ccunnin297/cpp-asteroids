#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

class Entity
{
    public:
        EntityState getState();
        void setState(EntityState& entityState);

        void update();
        virtual void draw(sf::RenderWindow& window);

        virtual EntityType getClassname() { return EntityType::ENTITY; };

        unsigned short m_id;
        sf::Vector2f m_position;
        float m_velocity;
        int m_rotation;

        bool m_forward;
        bool m_backward;
        bool m_turnLeft;
        bool m_turnRight;
    private:
};