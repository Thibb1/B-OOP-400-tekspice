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

void nts::C4069::simulate(size_t tick)
{
    (void) tick;
}

nts::Tristate nts::C4069::compute(size_t pin)
{
    switch (pin) {
        case 2:
            return Gate::Not(_links[1]->compute(_linksPin[1]));
        case 4:
            return Gate::Not(_links[3]->compute(_linksPin[3]));
        case 6:
            return Gate::Not(_links[5]->compute(_linksPin[5]));
        case 8:
            return Gate::Not(_links[9]->compute(_linksPin[9]));
        case 10:
            return Gate::Not(_links[11]->compute(_linksPin[11]));
        case 12:
            return Gate::Not(_links[13]->compute(_linksPin[13]));
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}
