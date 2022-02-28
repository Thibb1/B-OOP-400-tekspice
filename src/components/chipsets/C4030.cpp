/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4030.hpp"

nts::C4030::C4030()
{
    _nbPin = 14;
}

nts::C4030::~C4030()
{
}

nts::Tristate nts::C4030::compute(size_t pin)
{
    ++_cycle;
    if (_cycle >= 10000) {
        reset();
        return UNDEFINED;
    }
    switch (pin) {
        case 3:
            _values[3] = Gate::Xor(_links[1]->compute(_linksPin[1]), _links[2]->compute(_linksPin[2]));
            return _values.at(3);
        case 4:
            _values[4] = Gate::Xor(_links[5]->compute(_linksPin[5]), _links[6]->compute(_linksPin[6]));
            return _values.at(4);
        case 10:
            _values[10] = Gate::Xor(_links[8]->compute(_linksPin[8]), _links[9]->compute(_linksPin[9]));
            return _values.at(10);
        case 11:
            _values[11] = Gate::Xor(_links[12]->compute(_linksPin[12]), _links[13]->compute(_linksPin[13]));
            return _values.at(11);
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}

void nts::C4030::dump() const
{
    std::cout << "\n    03: " << getTristateString(3);
    std::cout << "\n    04: " << getTristateString(4);
    std::cout << "\n    10: " << getTristateString(10);
    std::cout << "\n    11: " << getTristateString(11) << std::endl;
}