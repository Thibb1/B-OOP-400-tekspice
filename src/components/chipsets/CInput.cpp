/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Input
*/

#include "CInput.hpp"

nts::CInput::CInput()
{
}

nts::CInput::~CInput()
{
}

nts::CInput *nts::CInput::clone() const
{
    return new CInput();
}

void nts::CInput::simulate(std::size_t tick)
{
    (void) tick;
    return;
}

nts::Tristate nts::CInput::compute(std::size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    return _value;
}

void nts::CInput::dump() const
{
    if IS_UNDEFINED(_value)
        std::cout << "U" << std::endl;
    else
        std::cout << _value << std::endl;
}