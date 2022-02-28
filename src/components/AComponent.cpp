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

std::string nts::AComponent::getTristateString(size_t pin) const
{
    Tristate state = UNDEFINED;
    if (_values.find(pin) != _values.end())
        state = _values.at(pin);
    if (state == UNDEFINED)
        return "U";
    else if (state == TRUE)
        return "1";
    else
        return "0";
}
