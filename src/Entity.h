#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.pb.h"

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

        unsigned short getId();
        void setId(unsigned short newId);
        sf::Vector2f getPosition();
        void setPosition(sf::Vector2f newPosition);
        float getRotation();
        void setRotation(float newRotation);
        float getVelocity();
        void setVelocity(float newVelocity);
        sf::Rect<float> getBoundingRect();
        void setCollisionOn(bool newCollisionOn);
    protected:
        virtual sf::Vector2f getBaseSize() { return sf::Vector2f(200, 200); };
        virtual std::string getTextureString() { return "entity.png"; };

        sf::Sprite m_sprite;
        sf::Texture m_texture;

        unsigned short m_id;
        sf::Vector2f m_position;
        sf::Vector2f m_size;
        float m_velocity;
        float m_rotation;
        bool m_collisionOn;

        bool m_destroy;
    private:
};