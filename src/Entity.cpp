#include "Entity.h"

#include "GameValues.h"
#include "utils.h"

#include <iostream>

Entity::Entity()
{
    m_rotation = 0.0f;
    m_velocity = 0.0f;
    m_collisionOn = false;
    m_destroy = false;
};

void Entity::init() {
    m_size = getBaseSize();
    //TODO: make this a bit smarter
    m_collisionRadius = m_size.x/2.0f;
    std::string filename = "assets/" + getTextureString();
    if (!m_texture.loadFromFile(filename)) {
        std::cout << "Missing asset:" << filename << std::endl;
    }
};

EntityState Entity::getState()
{
    EntityState entityState;
    entityState.set_id(m_id);
    entityState.set_type(getType());
    auto* position = entityState.mutable_position();
    position->set_x(m_position.x);
    position->set_y(m_position.y);
    entityState.set_rotation(m_rotation);
    entityState.set_destroy(m_destroy);
    return entityState;
};

void Entity::setState(EntityState& entityState)
{
    m_id = entityState.id();
    m_position = sf::Vector2f(entityState.position().x(), entityState.position().y());
    m_rotation = entityState.rotation();
    m_destroy = entityState.destroy();
};

bool Entity::collidesWith(Entity* entity)
{
    if (!entity->m_collisionOn || !entity->m_collisionOn) {
        return false;
    }
    //distance from centers < radius
    return distance(getCenter(), entity->getCenter()) < entity->getCollisionRadius() + getCollisionRadius();
};

void Entity::hasCollidedWith(Entity* entity)
{

};

void Entity::update()
{
    float radians = degreesToRadians(m_rotation);
    sf::Vector2f unitVector = unitVectorFromRadians(radians);
    sf::Vector2f velocityVector = unitVector * m_velocity;
    m_position += velocityVector;

    // if going offscreen, continue through the other side
    auto center = getCenter();
    if (center.x < 0) {
        m_position.x = GAME_BOUNDS_X - (0 - m_position.x);
    } else if (center.x > GAME_BOUNDS_X) {
        m_position.x = 0 + (m_position.x - GAME_BOUNDS_X);
    }
    if (center.y < 0) {
        m_position.y = GAME_BOUNDS_Y - (0 - m_position.y);
    } else if (center.y > GAME_BOUNDS_Y) {
        m_position.y = 0 + (m_position.y - GAME_BOUNDS_Y);
    }
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
    //TODO: see if floor is necessary
    m_sprite.setOrigin(m_sprite.getLocalBounds().width/2,m_sprite.getLocalBounds().height/2);

    //since origin is center and m_position is topLeft, adjust the spritePosition for sprite
    m_sprite.setPosition(getCenter());
    
    //Default rotation to up instead of facing to the side
    m_sprite.setRotation(90+m_rotation);

    window.draw(m_sprite);
};

ID Entity::getId()
{
    return m_id;
};

void Entity::setId(ID newId)
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

void Entity::setCollisionOn(bool newCollisionOn)
{
    m_collisionOn = newCollisionOn;
};

sf::Vector2f Entity::getCenter()
{
    return m_position + m_size / 2.0f;
};

float Entity::getCollisionRadius()
{
    return m_collisionRadius;
};

bool Entity::shouldDestroy()
{
    return m_destroy;
};

void Entity::destroy()
{
    m_destroy = true;
};