/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4001.hpp"

nts::C4001::C4001()
{
}

nts::C4001::~C4001()
{
}

void nts::C4001::simulate(size_t tick)
{
    (void) tick;
    if IS_UNDEFINED(_value)
        return;
    else
        setValue(_value == TRUE ? FALSE : TRUE);
}

nts::Tristate nts::C4001::compute(size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    return _value;
}
