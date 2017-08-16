#pragma once

#include "Entity.h"

class Asteroid : public Entity
{
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(100, 100); };
        std::string getTextureString() override { return "asteroid.png"; };
        EntityType getClassname() override { return EntityType::ASTEROID; };
    private:
};