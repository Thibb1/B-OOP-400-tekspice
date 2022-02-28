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
    ++_cycle;
    if (_cycle >= 10000) {
        reset();
        return UNDEFINED;
    }
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
            _values[3] = Gate::Nor(_flipFlop5.GetQ(), _flipFlop1.GetQ());
            return _values.at(3);
        case 2:
            _values[2] = Gate::Nor(_flipFlop2.GetQ(), _flipFlop1.GetQPrime());
            return _values.at(2);
        case 4:
            _values[4] = Gate::Nor(_flipFlop2.GetQPrime(), _flipFlop3.GetQ());
            return _values.at(4);
        case 7:
            _values[7] = Gate::Nor(_flipFlop4.GetQ(), _flipFlop3.GetQPrime());
            return _values.at(7);
        case 10:
            _values[10] = Gate::Nor(_flipFlop5.GetQ(), _flipFlop4.GetQPrime());
            return _values.at(10);
        case 1:
            _values[11] = Gate::Nor(_flipFlop1.GetQPrime(), _flipFlop5.GetQPrime());
            return _values.at(11);
        case 5:
            _values[5] = Gate::Nor(_flipFlop1.GetQ(), _flipFlop2.GetQPrime());
            return _values.at(5);
        case 6:
            _values[6] = Gate::Nor(_flipFlop2.GetQ(), _flipFlop3.GetQPrime());
            return _values.at(6);
        case 9:
            _values[9] = Gate::Nor(_flipFlop4.GetQPrime(), _flipFlop3.GetQ());
            return _values.at(9);
        case 11:
            _values[11] = Gate::Nor(_flipFlop4.GetQ(), _flipFlop5.GetQPrime());
            return _values.at(11);
        case 12:
            _values[12] = _flipFlop5.GetQPrime();
            return _values.at(12);
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}

void nts::C4017::dump() const
{
    std::cout << "\n    01: " << getTristateString(3);
    std::cout << "\n    02: " << getTristateString(2);
    std::cout << "\n    03: " << getTristateString(4);
    std::cout << "\n    04: " << getTristateString(7);
    std::cout << "\n    05: " << getTristateString(10);
    std::cout << "\n    06: " << getTristateString(1);
    std::cout << "\n    07: " << getTristateString(5);
    std::cout << "\n    08: " << getTristateString(6);
    std::cout << "\n    09: " << getTristateString(9);
    std::cout << "\n    10: " << getTristateString(11);
    std::cout << "\n    11: " << getTristateString(12) << std::endl;
}