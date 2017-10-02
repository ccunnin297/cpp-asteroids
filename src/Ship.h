#pragma once

#include "Entity.h"
#include "Bullet.h"

enum ShipType {
    BLUE = 0,
    RED = 1,
    GREEN = 2,
    ORANGE = 3
};

class Ship : public Entity
{
    public:
        Ship();

        EntityType getType() override { return EntityType::SHIP; };

        void setShipType(ShipType shipType);

        EntityState getState() override;
        void setState(const EntityState& entityState) override;

        void update(double deltas) override;
        void hasCollidedWith(Entity* entity) override;
    
        void setMoveForward(bool const newMoveForward);
        void setMoveBackward(bool const newMoveBackward);
        void setTurnLeft(bool const newTurnLeft);
        void setTurnRight(bool const newTurnRight);

        void shoot(Bullet* bullet);
    protected:
        sf::Vector2f getBaseSize() override { return sf::Vector2f(50, 50); };
        std::string getTextureString() override;

        ShipType m_shipType;

        bool m_moveForward;
        bool m_moveBackward;
        bool m_turnLeft;
        bool m_turnRight;
};