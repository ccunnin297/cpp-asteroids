#include "Asteroid.h"

Asteroid::Asteroid() : Entity()
{
    Entity::setCollisionOn(true);

    //NOTE: there is no need to sync this in the entitystate because it is client-side only.
    // It is only here to add some variety to sprites, so its state from the server doesn't matter
    m_asteroidType = static_cast<AsteroidType>(randi(0, 1));
};

std::string Asteroid::getTextureString()
{
    switch (m_asteroidType) {
        case ASTEROID1:
            return "asteroid1.png";
        case ASTEROID2:
            return "asteroid2.png";
    }
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