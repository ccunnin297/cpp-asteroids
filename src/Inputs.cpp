#include "Inputs.h"

Inputs::Inputs()
{
    m_state = 0;
};

bool Inputs::isKeyPressed(InputKey key)
{
    return m_state & m_keyMapping.at(key);
};

void Inputs::setState(uint32_t inputState)
{
    m_state = inputState;
};

void Inputs::update()
{
    uint32_t newState = 0;
    for (auto const& it : m_keyMapping) {
        if (sf::Keyboard::isKeyPressed(it.second)) {
            newState |= it.first;
        }
    }
    m_state = newState;
};