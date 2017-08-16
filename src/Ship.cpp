#include "Ship.h"

Ship::Ship() : Entity()
{
    m_moveForward = false;
    m_moveBackward = false;
    m_turnLeft = false;
    m_turnRight = false;

    Entity::setCollisionOn(true);
};

void Ship::update()
{
    m_velocity = 0.0f;
    if (m_moveForward) {
        m_velocity = 5;
    }
    if (m_moveBackward) {
        m_velocity = -5;
    }
    if (m_turnLeft) {
        m_rotation -= 3;
    }
    if (m_turnRight) {
        m_rotation += 3;
    }

    Entity::update();
};

void Ship::setMoveForward(bool const newMoveForward)
{
    m_moveForward = newMoveForward;
};

void Ship::setMoveBackward(bool const newMoveBackward)
{
    m_moveBackward = newMoveBackward;
};

void Ship::setTurnLeft(bool const newTurnLeft)
{
    m_turnLeft = newTurnLeft;
};

void Ship::setTurnRight(bool const newTurnRight)
{
    m_turnRight = newTurnRight;
};

void Ship::shoot(Bullet* bullet)
{
    //spawn bullet in middle of ship
    float bulletPositionX = m_position.x + (m_size.x / 2);
    float bulletPositionY = m_position.y + (m_size.y / 2);
    bullet->setPosition(sf::Vector2f(bulletPositionX, bulletPositionY));
    
    //should travel along the same angle as the ship's current rotation
    bullet->setRotation(m_rotation);

    bullet->setVelocity(5);
};

void Ship::hasCollidedWith(Entity* entity)
{
    auto type = entity->getType();
    switch (type) {
        case ASTEROID:
            Entity::destroy();
            break;
        default:
            break;
    }
};