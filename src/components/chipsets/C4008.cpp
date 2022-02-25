/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4008.hpp"

nts::C4008::C4008()
{
    _nbPin = 16;
}

nts::C4008::~C4008()
{
}

nts::Tristate nts::C4008::computeSum(Tristate a, Tristate b, Tristate c)
{
    if (a == UNDEFINED || b == UNDEFINED || c == UNDEFINED)
        return UNDEFINED;
    return Gate::Xor(Gate::Xor(a, b), c);
}

nts::Tristate nts::C4008::computeCarry(Tristate a, Tristate b, Tristate c)
{
    if (a == UNDEFINED || b == UNDEFINED || c == UNDEFINED)
        return UNDEFINED;
    return Gate::Or(Gate::And(a, b), Gate::And(Gate::Xor(a, b), c));
}

nts::Tristate nts::C4008::compute(size_t pin)
{
    Tristate a = _links[6]->compute(_linksPin[6]);
    Tristate b = _links[7]->compute(_linksPin[7]);
    Tristate c = _links[9]->compute(_linksPin[9]);
    Tristate d = _links[5]->compute(_linksPin[5]);
    Tristate e = _links[4]->compute(_linksPin[4]);
    Tristate f = _links[3]->compute(_linksPin[3]);
    Tristate g = _links[2]->compute(_linksPin[2]);
    Tristate h = _links[1]->compute(_linksPin[1]);
    Tristate i = _links[15]->compute(_linksPin[15]);
    Tristate s0 = computeSum(a, b, c);
    Tristate c0 = computeCarry(a, b, c);
    Tristate s1 = computeSum(c0, d, e);
    Tristate c1 = computeCarry(c0, d, e);
    Tristate s2 = computeSum(c1, f, g);
    Tristate c2 = computeCarry(c1, f, g);
    Tristate s3 = computeSum(c2, h, i);
    Tristate c3 = computeCarry(c2, h, i);

    switch (pin) {
        case 10:
            return s0;
        case 11:
            return s1;
        case 12:
            return s2;
        case 13:
            return s3;
        case 14:
            return c3;
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}
