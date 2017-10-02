#pragma once

#include "Entity.h"

#include "utils.h"

enum AsteroidType {
    ASTEROID1 = 0,
    ASTEROID2 = 1
};

class Asteroid : public Entity
{
    public:
        Asteroid();

        EntityType getType() override { return EntityType::ASTEROID; };

        void hasCollidedWith(Entity* entity) override;
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(100, 100); };
        std::string getTextureString() override {
            if (m_asteroidType == ASTEROID1) {
                return "asteroid1.png";
            } else {
                return "asteroid2.png";
            }
        };

        AsteroidType m_asteroidType;
    private:
};