/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4017.hpp"

nts::C4017::C4017()
{
    _nbPin = 16;
}

nts::C4017::~C4017()
{
}

nts::Tristate nts::C4017::compute(size_t pin)
{
    Tristate in_0 = _links[14]->compute(_linksPin[14]);
    Tristate in_1 = _links[13]->compute(_linksPin[13]);
    Tristate in_r = _links[15]->compute(_linksPin[15]);
    if (IS_UNDEFINED(in_0) || IS_UNDEFINED(in_1) || IS_UNDEFINED(in_r))
        return UNDEFINED;
    Tristate clock = Gate::And(in_0, Gate::Not(in_1));
    Tristate set = Gate::Not(in_r);
    Tristate flip1Q = _flipFlop1.GetQ();
    Tristate flip2Q = _flipFlop2.GetQ();
    Tristate flip3Q = _flipFlop3.GetQ();
    Tristate flip4Q = _flipFlop4.GetQ();
    Tristate flip5QPrime = _flipFlop5.GetQPrime();
    _flipFlop1.compute(clock, flip5QPrime, set);
    _flipFlop2.compute(clock, flip1Q, set);
    Tristate data_3 = Gate::And(flip2Q, Gate::Or(flip1Q, flip3Q));
    _flipFlop3.compute(clock, data_3, set);
    _flipFlop4.compute(clock, flip3Q, set);
    _flipFlop5.compute(clock, flip4Q, set);
    switch (pin) {
        case 3:
            return Gate::Nor(_flipFlop5.GetQ(), _flipFlop1.GetQ());
        case 2:
            return Gate::Nor(_flipFlop2.GetQ(), _flipFlop1.GetQPrime());
        case 4:
            return Gate::Nor(_flipFlop2.GetQPrime(), _flipFlop3.GetQ());
        case 7:
            return Gate::Nor(_flipFlop4.GetQ(), _flipFlop3.GetQPrime());
        case 10:
            return Gate::Nor(_flipFlop5.GetQ(), _flipFlop4.GetQPrime());
        case 1:
            return Gate::Nor(_flipFlop1.GetQPrime(), _flipFlop5.GetQPrime());
        case 5:
            return Gate::Nor(_flipFlop1.GetQ(), _flipFlop2.GetQPrime());
        case 6:
            return Gate::Nor(_flipFlop2.GetQ(), _flipFlop3.GetQPrime());
        case 9:
            return Gate::Nor(_flipFlop4.GetQPrime(), _flipFlop3.GetQ());
        case 11:
            return Gate::Nor(_flipFlop4.GetQ(), _flipFlop5.GetQPrime());
        case 12:
            return _flipFlop5.GetQPrime();
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}
