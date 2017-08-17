#include "Bullet.h"

#include "GameValues.h"

Bullet::Bullet() : Entity()
{
    m_traveledDistance = 0;
    Entity::setCollisionOn(true);
};

void Bullet::update()
{
    Entity::update();
    m_traveledDistance += Entity::getVelocity();
    if (m_traveledDistance > MAX_BULLET_DISTANCE) {
        Entity::destroy();
    }
};

void Bullet::hasCollidedWith(Entity* entity)
{
    switch (entity->getType()) {
        case ASTEROID:
            Entity::destroy();
            break;
        default:
            break;
    }
};