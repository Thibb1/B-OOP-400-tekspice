/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** AComponent
*/

#include "AComponent.hpp"

nts::Tristate nts::AComponent::getPins(size_t pin)
{
    ++_cycle;
    if (_cycle > MAX_CYCLE)
        return UNDEFINED;
    if (pin >= _links.size() || pin < 0)
        return UNDEFINED;
    return _links[pin].second.compute(_links[pin].first);
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (pin >= _links.size() || pin < 0)
        throw std::invalid_argument("PinError: pin out of range");
    _links[pin] = std::make_pair(otherPin, other);
}

void nts::AComponent::reset(void)
{
    _cycle = 0;
}
