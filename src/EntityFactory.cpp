#include "EntityFactory.h"

EntityFactory::EntityFactory()
{
    m_autoIncrement = 0;
};

//Instantiates new entity based on specified type from state
std::unique_ptr<Entity> EntityFactory::makeFromState(EntityState& entityState) {
    std::unique_ptr<Entity> e;
    switch (entityState.type()) {
        case BULLET:
            e = (std::unique_ptr<Entity>)std::make_unique<Bullet>();
            break;
        case SHIP:
            e = (std::unique_ptr<Entity>)std::make_unique<Ship>();
            break;
        case ASTEROID:
            e = (std::unique_ptr<Entity>)std::make_unique<Asteroid>();
            break;
        default:
            e = std::make_unique<Entity>();
            break;
    }
    e->init();
    e->setState(entityState);
    return e;
};