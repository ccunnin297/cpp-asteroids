#pragma once

#include <memory>

#include "utils.h"

#include "Entity.h"
#include "GameState.pb.h"
#include "Ship.h"
#include "Asteroid.h"
#include "Bullet.h"

//Entity Factory creates new entities and manages entity unique ID
class EntityFactory
{
    public:
        EntityFactory();
        template <class T> std::unique_ptr<T> make() {
            ++m_autoIncrement;
            T t = T();
            t.setId(m_autoIncrement);
            t.init();
            return std::make_unique<T>(t);
        };
        std::unique_ptr<Entity> makeFromState(EntityState& entityState);
    private:
        ID m_autoIncrement;
};