#pragma once

#include "Entity.h"

class Ship : public Entity
{
    public:
        void draw(sf::RenderWindow& window) override;

        EntityType getClassname() override { return EntityType::SHIP; };
    private:
};