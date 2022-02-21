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

nts::COutput *nts::COutput::clone() const
{
    return new COutput();
}

void nts::COutput::simulate(std::size_t tick)
{
    (void) tick;
    return;
}

nts::Tristate nts::COutput::compute(std::size_t pin)
{
    if (pin != 1)
        throw std::runtime_error("PinError: pin out of range");
    if (_links.size() == 0)
        return UNDEFINED;
    return _links[0]->compute(_linksPin[0]);
}

void nts::COutput::dump() const
{
    if IS_UNDEFINED(_value)
        std::cout << "U" << std::endl;
    else
        std::cout << _value << std::endl;
}