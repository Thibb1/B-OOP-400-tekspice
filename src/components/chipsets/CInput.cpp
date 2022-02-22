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

void nts::CInput::simulate(size_t tick)
{
    (void) tick;
}

nts::Tristate nts::CInput::compute(size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    return _value;
}
