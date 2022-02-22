/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4001.hpp"

nts::C4001::C4001()
{
    _nbPin = 14;
}

nts::C4001::~C4001()
{
}

void nts::C4001::simulate(size_t [[maybe_unused]] tick)
{
    if IS_UNDEFINED(_value)
        return;
    else
        setValue(_value == TRUE ? FALSE : TRUE);
}

nts::Tristate nts::C4001::compute(size_t pin)
{
    switch (pin) {
        case 3:
            // implement NOR gate
            return TRUE;
        case 4:
            // implement NOR gate
            return TRUE;
        case 10:
            // implement NOR gate
            return TRUE;
        case 11:
            // implement NOR gate
            return TRUE;
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}
