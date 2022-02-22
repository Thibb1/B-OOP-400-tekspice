/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** COutput
*/

#include "COutput.hpp"

nts::COutput::COutput()
{
}

nts::COutput::~COutput()
{
}

void nts::COutput::simulate(size_t tick)
{
    ++_cycle;
    if (_cycle > 10000 || !tick || tick > _links.size()) {
        setValue(UNDEFINED);
        return;
    }
    setValue(_links[tick]->compute(_linksPin[tick]));
}

nts::Tristate nts::COutput::compute(size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    if (_links.size() == 0)
        return UNDEFINED;
    return _links[1]->compute(_linksPin[1]);
}
