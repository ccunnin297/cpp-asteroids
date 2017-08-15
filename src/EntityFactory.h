#pragma once

// #include "Entity.h"

#include <memory>

class EntityFactory
{
    public:
        EntityFactory();
        template <typename T> std::unique_ptr<T> make() {
            ++m_autoIncrement;
            return std::make_unique<T>(m_autoIncrement);
        };
    private:
        unsigned short m_autoIncrement;
};