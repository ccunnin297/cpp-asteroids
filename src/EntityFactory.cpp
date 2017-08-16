#include "EntityFactory.h"

#include "Ship.h"

#include <iostream>

EntityFactory::EntityFactory()
{
    m_autoIncrement = 0;
};

std::unique_ptr<Entity> EntityFactory::makeFromState(EntityState& entityState) {
    std::unique_ptr<Entity> e;
    switch (entityState.type()) {
        case EntityType::SHIP:
            e = (std::unique_ptr<Entity>)std::make_unique<Ship>();
            break;
        default:
            e = std::make_unique<Entity>();
            break;
    }
    e->setState(entityState);
    return e;
};