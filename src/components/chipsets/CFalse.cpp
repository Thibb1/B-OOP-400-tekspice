/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CFalse
*/

#include "CFalse.hpp"

nts::CFalse::CFalse()
{
    _value = FALSE;
}

nts::CFalse::~CFalse()
{
}

void nts::CFalse::simulate(std::size_t tick)
{
    (void) tick;
}

nts::Tristate nts::CFalse::compute(std::size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    return _value;
}
