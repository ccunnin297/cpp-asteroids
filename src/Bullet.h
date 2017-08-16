#pragma once

#include "Entity.h"

class Bullet : public Entity
{
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(10, 10); };
        std::string getTextureString() override { return "bullet.png"; };
        EntityType getClassname() override { return EntityType::BULLET; };
    private:
};