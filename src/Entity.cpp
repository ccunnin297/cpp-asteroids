#include "Entity.h"

#include <cmath>
#include <iostream>

Entity::Entity()
{
    m_moveForward = false;
    m_moveBackward = false;
    m_turnLeft = false;
    m_turnRight = false;

    m_rotation = 0.0f;
    m_velocity = 0.0f;
};

void Entity::init() {
    m_size = getBaseSize();
    std::string filename = "assets/" + getTextureString();
    if (!m_texture.loadFromFile(filename)) {
        std::cout << "Missing asset:" << filename << std::endl;
    }
};

EntityState Entity::getState()
{
    EntityState entityState;
    entityState.set_id(m_id);
    entityState.set_type(getClassname());
    auto* position = entityState.mutable_position();
    position->set_x(m_position.x);
    position->set_y(m_position.y);
    entityState.set_rotation(m_rotation);
    return entityState;
};

void Entity::setState(EntityState& entityState)
{
    m_id = entityState.id();
    m_position = sf::Vector2f(entityState.position().x(), entityState.position().y());
    m_rotation = entityState.rotation();
};

void Entity::update()
{
    m_velocity = 0.0f;

    if (m_moveForward) {
        m_velocity = 5;
    }

    if (m_moveBackward) {
        m_velocity -= 5;
    }

    if (m_turnLeft) {
        m_rotation -= 1;
    }

    if (m_turnRight) {
        m_rotation += 1;
    }

    float radians = m_rotation * M_PI / 180.0f;
    float len = sqrt(pow(cos(radians),2)+pow(sin(radians),2));
    sf::Vector2f velocityVector = sf::Vector2f(cos(radians), sin(radians))/len * m_velocity;
    m_position += velocityVector;
};

void Entity::draw(sf::RenderWindow& window)
{
    m_sprite.setOrigin(floor(m_sprite.getLocalBounds().width/2),floor(m_sprite.getLocalBounds().height/2));
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(m_position);
    m_sprite.setRotation(90+m_rotation);
    window.draw(m_sprite);
};

unsigned short Entity::getId()
{
    return m_id;
};

void Entity::setId(unsigned short newId)
{
    m_id = newId;
};

sf::Vector2f Entity::getPosition()
{
    return m_position;
};

void Entity::setPosition(sf::Vector2f newPosition)
{
    m_position = newPosition;
};

void Entity::setMoveForward(bool const newMoveForward)
{
    m_moveForward = newMoveForward;
};

void Entity::setMoveBackward(bool const newMoveBackward)
{
    m_moveBackward = newMoveBackward;
};

void Entity::setTurnLeft(bool const newTurnLeft)
{
    m_turnLeft = newTurnLeft;
};

void Entity::setTurnRight(bool const newTurnRight)
{
    m_turnRight = newTurnRight;
};