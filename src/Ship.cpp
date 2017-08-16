#include "Ship.h"

void Ship::draw(sf::RenderWindow& window)
{
    sf::CircleShape triangle(25, 3);
    triangle.setPosition(m_position);
    triangle.setRotation(m_rotation);
    triangle.setFillColor(sf::Color(0, 50, 200));
    window.draw(triangle);
};