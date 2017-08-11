#include "Inputs.h"

Inputs::Inputs()
{
};

void Inputs::update()
{
    uint32_t newState = 0;
    for (auto const& it : m_keyMapping) {
        newState |= it.second;
    }
    m_keyState = newState;
};