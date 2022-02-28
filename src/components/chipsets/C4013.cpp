/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4013.hpp"

nts::C4013::C4013()
{
    _nbPin = 16;
}

nts::C4013::~C4013()
{
}

nts::Tristate nts::C4013::compute(size_t pin)
{
    ++_cycle;
    if (_cycle >= 10000) {
        reset();
        return UNDEFINED;
    }
    _flipFlop1.compute(
        _links[3]->compute(_linksPin[3]),
        _links[5]->compute(_linksPin[5]),
        _links[6]->compute(_linksPin[6]),
        _links[4]->compute(_linksPin[4])
    );
    _flipFlop2.compute(
        _links[11]->compute(_linksPin[11]),
        _links[9]->compute(_linksPin[9]),
        _links[8]->compute(_linksPin[8]),
        _links[10]->compute(_linksPin[10])
    );
    switch (pin) {
        case 1:
            _values[1] = _flipFlop1.GetQ();
            return _values.at(1);
        case 2:
            _values[2] = _flipFlop1.GetQPrime();
            return _values.at(2);
        case 12:
            _values[12] = _flipFlop2.GetQPrime();
            return _values.at(12);
        case 13:
            _values[13] = _flipFlop2.GetQ();
            return _values.at(13);
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}

void nts::C4013::dump() const
{
    std::cout << "\n    01: " << getTristateString(1);
    std::cout << "\n    02: " << getTristateString(2);
    std::cout << "\n    12: " << getTristateString(12);
    std::cout << "\n    13: " << getTristateString(13) << std::endl;
}