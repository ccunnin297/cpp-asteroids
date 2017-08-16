#include "Entity.h"

#include <cmath>

EntityState Entity::getState()
{
    EntityState entityState;
    entityState.set_id(m_id);
    entityState.set_type(getClassname());
    auto* position = entityState.mutable_position();
    position->set_x(m_position.x);
    position->set_y(m_position.y);
    
    return entityState;
};

void Entity::setState(EntityState& entityState)
{
    m_id = entityState.id();
    m_position = sf::Vector2f(entityState.position().x(), entityState.position().y());
};

void Entity::update()
{
    m_velocity = 0;

    if (m_forward) {
        m_velocity -= 5;
    }

    if (m_backward) {
        m_velocity += 5;
    }

    if (m_turnLeft) {
        m_rotation -= 1;
    }

    if (m_turnRight) {
        m_rotation += 1;
    }

    float radians = m_rotation * 180.0f / M_PI;
    float len = sqrt(pow(cos(radians),2)+pow(sin(radians),2));
    sf::Vector2f velocityVector = sf::Vector2f(cos(radians), sin(radians))/len * m_velocity;
    m_position += velocityVector;
};

void Entity::draw(sf::RenderWindow& window)
{
    sf::CircleShape circle(50);
    circle.setPosition(m_position);
    circle.setFillColor(sf::Color(100, 250, 50));
    window.draw(circle);
};