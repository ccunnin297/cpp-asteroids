#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

#include "utils.h"

class Entity
{
    public:
        Entity();

        virtual EntityType getType() { return EntityType::ENTITY; };

        void init();
        virtual void update();
        void draw(sf::RenderWindow& window);

        EntityState getState();
        void setState(EntityState& entityState);

        bool collidesWith(Entity* entity);
        virtual void hasCollidedWith(Entity* entity);

        bool shouldDestroy();
        void destroy();

        ID getId();
        void setId(ID newId);
        sf::Vector2f getPosition();
        void setPosition(sf::Vector2f newPosition);
        float getRotation();
        void setRotation(float newRotation);
        float getVelocity();
        void setVelocity(float newVelocity);
        void setCollisionOn(bool newCollisionOn);
        sf::Vector2f getCenter();
        float getCollisionRadius();
    protected:
        virtual sf::Vector2f getBaseSize() { return sf::Vector2f(200, 200); };
        virtual std::string getTextureString() { return "entity.png"; };

        sf::Sprite m_sprite;

        ID m_id;
        sf::Vector2f m_position;
        sf::Vector2f m_size;
        float m_velocity;
        float m_rotation;
        float m_collisionRadius;
        bool m_collisionOn;

        bool m_destroy;
    private:
};