#include "Bullet.h"

Bullet::Bullet() : Entity()
{
    Entity::setCollisionOn(true);
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