/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (pin > _nbPin)
        throw std::invalid_argument("PinError: pin out of range");
    _links[pin] = &other;
    _linksPin[pin] = otherPin;
}

void nts::AComponent::reset(void)
{
    _cycle = 0;
}

void nts::AComponent::setValue(nts::Tristate state)
{
    _value = state;
}

void nts::AComponent::dump() const
{
    if (IS_UNDEFINED(_value))
        std::cout << "U" << std::endl;
    else
        std::cout << _value << std::endl;
}

void nts::AComponent::simulate(size_t tick)
{
    (void) tick;
}