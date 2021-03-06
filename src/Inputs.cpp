#include "Inputs.h"

Inputs::Inputs()
{
    m_state = std::make_unique<InputState>();
    m_state->set_key_pressed(0);
    m_state->set_key_released(0);
};

Inputs::Inputs(InputState inputState)
{
    m_state = std::make_unique<InputState>();
    setState(inputState);
};

bool Inputs::isKeyPressed(InputKey key)
{
    return m_state->key_pressed() & key;
};

bool Inputs::isKeyReleased(InputKey key)
{
    return m_state->key_released() & key;
};

InputState Inputs::getState()
{
    InputState inputState;
    inputState.CopyFrom(*m_state);
    return inputState;
};

void Inputs::setState(InputState inputState)
{
    m_state->CopyFrom(inputState);
};

void Inputs::update(sf::Event event)
{
    for (auto const& it : m_keyMapping) {
        if (event.key.code == it.second) {
            if (event.type == sf::Event::KeyPressed) {
                 m_state->set_key_pressed(m_state->key_pressed()|it.first);
                 m_state->set_key_released(m_state->key_released()&~it.first);
            } else if(event.type == sf::Event::KeyReleased) {
                m_state->set_key_released(m_state->key_released()|it.first);
                m_state->set_key_pressed(m_state->key_pressed()&~it.first);
            }
        }
    }
};