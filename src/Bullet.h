#pragma once

#include "Entity.h"

class Bullet : public Entity
{
    public:
        Bullet();

        EntityType getType() const override { return EntityType::BULLET; };
        
        void update(double deltas) override;
        void hasCollidedWith(Entity* entity) override;
    protected:
        sf::Vector2f getBaseSize() const override { return sf::Vector2f(10, 10); };
        std::string getTextureString() const override { return "bullet.png"; };
    private:
        float m_traveledDistance;
};