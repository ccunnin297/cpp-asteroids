#include "Ship.h"

Ship::Ship(unsigned short id) : Entity(id)
{

};

void Ship::draw(sf::RenderWindow& window)
{
    sf::CircleShape circle(25);
    circle.setPosition(m_position);
    circle.setFillColor(sf::Color(0, 50, 200));
    window.draw(circle);
};