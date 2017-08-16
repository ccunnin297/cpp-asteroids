#include "Asteroid.h"

Asteroid::Asteroid() : Entity()
{
    Entity::setCollisionOn(true);
};

void Asteroid::hasCollidedWith(Entity* entity)
{
    //TODO: figure out types instead of switch
    auto type = entity->getType();
    switch (type) {
        case BULLET:
            Entity::destroy();
            break;
        default:
            break;
    }
};