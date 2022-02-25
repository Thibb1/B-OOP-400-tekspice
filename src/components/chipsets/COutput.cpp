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
    (void) tick;
    setValue(compute(tick));
}

nts::Tristate nts::COutput::compute(size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    if (_links.size() == 0)
        return UNDEFINED;
    Tristate value = _links[1]->compute(_linksPin[1]);
    _links[1]->reset();
    return value;
}
