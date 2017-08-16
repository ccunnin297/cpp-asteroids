#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

class Entity
{
    public:
        Entity();

        void init();
        EntityState getState();
        void setState(EntityState& entityState);
        void update();
        void draw(sf::RenderWindow& window);

        unsigned short getId();
        void setId(unsigned short newId);

        sf::Vector2f getPosition();
        void setPosition(sf::Vector2f newPosition);

        void setMoveForward(bool const newMoveForward);
        void setMoveBackward(bool const newMoveBackward);
        void setTurnLeft(bool const newTurnLeft);
        void setTurnRight(bool const newTurnRight);
    protected:
        virtual sf::Vector2f getBaseSize() { return sf::Vector2f(200, 200); };
        virtual std::string getTextureString() { return "entity.png"; };
        virtual EntityType getClassname() { return EntityType::ENTITY; };

        sf::Sprite m_sprite;
        sf::Texture m_texture;

        unsigned short m_id;
        sf::Vector2f m_position;
        sf::Vector2f m_size;
        float m_velocity;
        float m_rotation;

        bool m_moveForward;
        bool m_moveBackward;
        bool m_turnLeft;
        bool m_turnRight;
    private:
};