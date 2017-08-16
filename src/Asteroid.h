#pragma once

#include "Entity.h"

class Asteroid : public Entity
{
    public:
        Asteroid();

        EntityType getType() override { return EntityType::ASTEROID; };

        void hasCollidedWith(Entity* entity) override;
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(100, 100); };
        std::string getTextureString() override { return "asteroid.png"; };
    private:
};