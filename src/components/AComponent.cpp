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
    if (_cycle > 10000)
        return UNDEFINED;
    if (pin >= _links.size())
        return UNDEFINED;
    return _links[pin]->compute(_linksPin[pin]);
}

void nts::AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    if (pin >= _links.size())
        throw std::invalid_argument("PinError: pin out of range");
    _links[pin] = &other;
    _linksPin[pin] = otherPin;
}

void nts::AComponent::reset(void)
{
    _cycle = 0;
}
