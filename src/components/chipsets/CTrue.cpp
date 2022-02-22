/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** CTrue
*/

#include "CTrue.hpp"

nts::CTrue::CTrue()
{
    _value = TRUE;
}

nts::CTrue::~CTrue()
{
}

void nts::CTrue::simulate(size_t tick)
{
    (void) tick;
}

nts::Tristate nts::CTrue::compute(size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    return _value;
}
