/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4081.hpp"

nts::C4081::C4081()
{
    _nbPin = 14;
}

nts::C4081::~C4081()
{
}

nts::Tristate nts::C4081::compute(size_t pin)
{
    switch (pin) {
        case 3:
            return Gate::And(_links[1]->compute(_linksPin[1]), _links[2]->compute(_linksPin[2]));
        case 4:
            return Gate::And(_links[5]->compute(_linksPin[5]), _links[6]->compute(_linksPin[6]));
        case 10:
            return Gate::And(_links[8]->compute(_linksPin[8]), _links[9]->compute(_linksPin[9]));
        case 11:
            return Gate::And(_links[12]->compute(_linksPin[12]), _links[13]->compute(_linksPin[13]));
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}
