#include "EntityFactory.h"

#include <iostream>

EntityFactory::EntityFactory()
{
    m_autoIncrement = 0;
};

std::unique_ptr<Entity> EntityFactory::makeFromState(EntityState& entityState) {
    std::unique_ptr<Entity> e;
    switch (entityState.type()) {
        case EntityType::BULLET:
            e = (std::unique_ptr<Entity>)std::make_unique<Bullet>();
            break;
        case EntityType::SHIP:
            e = (std::unique_ptr<Entity>)std::make_unique<Ship>();
            break;
        case EntityType::ASTEROID:
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