#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

class Entity
{
    public:
        Entity();

        void init();
        virtual void update();
        void draw(sf::RenderWindow& window);

        EntityState getState();
        void setState(EntityState& entityState);

        unsigned short getId();
        void setId(unsigned short newId);
        sf::Vector2f getPosition();
        void setPosition(sf::Vector2f newPosition);
        float getRotation();
        void setRotation(float newRotation);
        float getVelocity();
        void setVelocity(float newVelocity);
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
    private:
};