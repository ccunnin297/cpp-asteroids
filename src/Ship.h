#pragma once

#include "Entity.h"

class Ship : public Entity
{
    public:
        Ship(unsigned short id);
        virtual void draw(sf::RenderWindow& window);
    private:
};