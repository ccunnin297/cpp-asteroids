#include "Ship.h"

#include "GameValues.h"

Ship::Ship() : Entity()
{
    m_moveForward = false;
    m_moveBackward = false;
    m_turnLeft = false;
    m_turnRight = false;
    m_shipType = BLUE;

    Entity::setCollisionOn(true);
};

void Ship::setShipType(ShipType shipType)
{
    m_shipType = shipType;
};

std::string Ship::getTextureString()
{
    switch (m_shipType) {
        case BLUE:
            return "ship1.png";
        case RED:
            return "ship2.png";
        case GREEN:
            return "ship3.png";
        case ORANGE:
            return "ship4.png";
    }
};

EntityState Ship::getState()
{
    EntityState entityState = Entity::getState();
    entityState.set_subtype(m_shipType);
    return entityState;
};

void Ship::setState(const EntityState& entityState)
{
    Entity::setState(entityState);
    m_shipType = static_cast<ShipType>(entityState.subtype());
};

void Ship::update(double deltas)
{
    m_velocity = 0.0f;
    if (m_moveForward) {
        m_velocity = SHIP_VELOCITY;
    }
    if (m_moveBackward) {
        m_velocity = -SHIP_VELOCITY;
    }
    if (m_turnLeft) {
        m_rotation -= SHIP_TURN_SPEED * deltas;
    }
    if (m_turnRight) {
        m_rotation += SHIP_TURN_SPEED * deltas;
    }

    Entity::update(deltas);
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

    bullet->setVelocity(BULLET_VELOCITY);
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