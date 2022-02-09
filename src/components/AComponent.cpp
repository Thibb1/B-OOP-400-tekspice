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
    if (_cycle > nts::MAX_CYCLE)
        return (nts::UNDEFINED);
    
}

