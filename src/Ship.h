#pragma once

#include "Entity.h"
#include "Bullet.h"

class Ship : public Entity
{
    public:
        Ship();

        EntityType getType() override { return EntityType::SHIP; };

        void update() override;
        void hasCollidedWith(Entity* entity) override;
    
        void setMoveForward(bool const newMoveForward);
        void setMoveBackward(bool const newMoveBackward);
        void setTurnLeft(bool const newTurnLeft);
        void setTurnRight(bool const newTurnRight);

        void shoot(Bullet* bullet);
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(50, 50); };
        std::string getTextureString() override { return "ship.png"; };

        bool m_moveForward;
        bool m_moveBackward;
        bool m_turnLeft;
        bool m_turnRight;
};