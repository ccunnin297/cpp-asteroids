#pragma once

#include "Entity.h"

class Bullet : public Entity
{
    public:
        Bullet();

        EntityType getType() override { return EntityType::BULLET; };
        
        void hasCollidedWith(Entity* entity) override;
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(10, 10); };
        std::string getTextureString() override { return "bullet.png"; };
    private:
};