#include "Entity.h"

#include <cmath>
#include <iostream>

Entity::Entity()
{
    m_rotation = 0.0f;
    m_velocity = 0.0f;
    m_collisionOn = false;
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

bool Entity::collidesWith(Entity* entity)
{
    if (!entity->m_collisionOn || !entity->m_collisionOn) {
        return false;
    }
    return getBoundingRect().intersects(entity->getBoundingRect());
};

void Entity::hasCollidedWith(Entity* entity)
{
    std::cout << "EVERYBODY RUN" << std::endl;
};

void Entity::update()
{
    float radians = m_rotation * M_PI / 180.0f;
    float len = sqrt(pow(cos(radians),2)+pow(sin(radians),2));
    sf::Vector2f velocityVector = sf::Vector2f(cos(radians), sin(radians))/len * m_velocity;
    m_position += velocityVector;
};

void Entity::draw(sf::RenderWindow& window)
{
    //TODO: use textureManager
    m_sprite.setTexture(m_texture);

    //ensure sprite is m_size, so scale up/down from texture size
    float xScale = m_size.x / m_texture.getSize().x;
    float yScale = m_size.y / m_texture.getSize().y;
    m_sprite.setScale(xScale, yScale);

    //center sprite on middle
    //floor
    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2,m_sprite.getLocalBounds().height/2);

    //since origin is center and m_position is topLeft, adjust the spritePosition for sprite
    float spritePosX = m_position.x+m_sprite.getLocalBounds().width/2;
    float spritePosY = m_position.y+m_sprite.getLocalBounds().height/2;
    m_sprite.setPosition(sf::Vector2f(spritePosX, spritePosY));
    
    //Default rotation to up instead of facing to the side
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

float Entity::getRotation()
{
    return m_rotation;
};

void Entity::setRotation(float newRotation)
{
    m_rotation = newRotation;
};

float Entity::getVelocity()
{
    return m_velocity;
};

void Entity::setVelocity(float newVelocity)
{
    m_velocity = newVelocity;
};

sf::Rect<float> Entity::getBoundingRect()
{
    return sf::Rect<float>(m_position.x, m_position.y, m_size.x, m_size.y);
};

void Entity::setCollisionOn(bool newCollisionOn)
{
    m_collisionOn = newCollisionOn;
};