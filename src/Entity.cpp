#include "Entity.h"

Entity::Entity(int id)
{
    m_id = id;
};

Entity::Entity(EntityState& entityState)
{
    m_id = entityState.id();
    setState(entityState);
}

EntityState Entity::getState()
{
    // auto entityState = std::make_unique<EntityState>();
    EntityState entityState;
    entityState.set_id(m_id);

    // entityState->set_position(new PositionState());
    // auto position = std::make_unique<PositionState>();
    auto* position = entityState.mutable_position();
    position->set_x(m_position.x);
    position->set_y(m_position.y);
    
    return entityState;
};

void Entity::setState(EntityState& entityState)
{
    m_position = sf::Vector2f(entityState.position().x(), entityState.position().y());
};

void Entity::update()
{
    m_position += m_velocity;
};