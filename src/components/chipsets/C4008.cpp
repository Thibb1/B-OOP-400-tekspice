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
    ++_cycle;
    if (_cycle >= 10000) {
        reset();
        return UNDEFINED;
    }
    Tristate a = _links[6]->compute(_linksPin[6]);
    Tristate b = _links[7]->compute(_linksPin[7]);
    Tristate c = _links[9]->compute(_linksPin[9]);
    Tristate d = _links[5]->compute(_linksPin[5]);
    Tristate e = _links[4]->compute(_linksPin[4]);
    Tristate f = _links[3]->compute(_linksPin[3]);
    Tristate g = _links[2]->compute(_linksPin[2]);
    Tristate h = _links[1]->compute(_linksPin[1]);
    Tristate i = _links[15]->compute(_linksPin[15]);
    _values[10] = computeSum(a, b, c);
    Tristate c0 = computeCarry(a, b, c);
    _values[11] = computeSum(c0, d, e);
    Tristate c1 = computeCarry(c0, d, e);
    _values[12] = computeSum(c1, f, g);
    Tristate c2 = computeCarry(c1, f, g);
    _values[13] = computeSum(c2, h, i);
    _values[14] = computeCarry(c2, h, i);

    switch (pin) {
        case 10:
            return _values.at(10);
        case 11:
            return _values.at(11);
        case 12:
            return _values.at(12);
        case 13:
            return _values.at(13);
        case 14:
            return _values.at(14);
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}

void nts::C4008::dump() const
{
    std::cout << "\n    10: " << getTristateString(10);
    std::cout << "\n    11: " << getTristateString(11);
    std::cout << "\n    12: " << getTristateString(12);
    std::cout << "\n    13: " << getTristateString(13);
    std::cout << "\n    14: " << getTristateString(14) << std::endl;
}