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
    _flipFlop1.compute(
        _links[3]->compute(_linksPin[3]),
        _links[4]->compute(_linksPin[4]),
        _links[5]->compute(_linksPin[5]),
        _links[6]->compute(_linksPin[6])
    );
    _flipFlop2.compute(
        _links[11]->compute(_linksPin[11]),
        _links[10]->compute(_linksPin[10]),
        _links[9]->compute(_linksPin[9]),
        _links[8]->compute(_linksPin[8])
    );
    switch (pin) {
        case 1:
            return _flipFlop1.GetQ();
        case 2:
            return _flipFlop1.GetQPrime();
        case 12:
            return _flipFlop2.GetQPrime();
        case 13:
            return _flipFlop2.GetQ();
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}
