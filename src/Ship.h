#pragma once

#include "Entity.h"

class Ship : public Entity
{
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(200, 200); };
        std::string getTextureString() override { return "ship.png"; };
        EntityType getClassname() override { return EntityType::SHIP; };
    private:
};