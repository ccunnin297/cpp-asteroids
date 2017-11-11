#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

#include "utils.h"

class Entity
{
    public:
        Entity();

        virtual EntityType getType() const { return EntityType::ENTITY; };

        void init();
        virtual void update(double deltas);
        void draw(sf::RenderWindow& window);

        virtual EntityState getState() const;
        virtual void setState(const EntityState& entityState);

        bool collidesWith(Entity* entity) const;
        virtual void hasCollidedWith(Entity* entity);

        bool shouldDestroy() const;
        void destroy();

        ID getId() const;
        void setId(ID newId);
        sf::Vector2f getPosition() const;
        void setPosition(sf::Vector2f newPosition);
        float getRotation() const;
        void setRotation(float newRotation);
        float getVelocity() const;
        void setVelocity(float newVelocity);
        void setCollisionOn(bool newCollisionOn);
        sf::Vector2f getCenter() const;
        float getCollisionRadius() const;
    protected:
        virtual sf::Vector2f getBaseSize() const { return sf::Vector2f(200, 200); };
        virtual std::string getTextureString() const { return "entity.png"; };

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