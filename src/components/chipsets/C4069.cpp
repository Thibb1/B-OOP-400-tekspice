/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4069.hpp"

nts::C4069::C4069()
{
    _nbPin = 14;
}

nts::C4069::~C4069()
{
}

nts::Tristate nts::C4069::compute(size_t pin)
{
    ++_cycle;
    if (_cycle >= 10000) {
        reset();
        return UNDEFINED;
    }
    switch (pin) {
        case 2:
            _values[2] = Gate::Not(_links[1]->compute(_linksPin[1]));
            return _values.at(2);
        case 4:
            _values[4] = Gate::Not(_links[3]->compute(_linksPin[3]));
            return _values.at(4);
        case 6:
            _values[6] = Gate::Not(_links[5]->compute(_linksPin[5]));
            return _values.at(6);
        case 8:
            _values[8] = Gate::Not(_links[9]->compute(_linksPin[9]));
            return _values.at(8);
        case 10:
            _values[10] = Gate::Not(_links[11]->compute(_linksPin[11]));
            return _values.at(10);
        case 12:
            _values[12] = Gate::Not(_links[13]->compute(_linksPin[13]));
            return _values.at(12);
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}

void nts::C4069::dump() const
{
    std::cout << "\n    02: " << getTristateString(2);
    std::cout << "\n    04: " << getTristateString(4);
    std::cout << "\n    06: " << getTristateString(6);
    std::cout << "\n    08: " << getTristateString(8);
    std::cout << "\n    10: " << getTristateString(10);
    std::cout << "\n    12: " << getTristateString(12) << std::endl;
}