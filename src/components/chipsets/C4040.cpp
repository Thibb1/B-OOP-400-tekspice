/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitach/tekspice
** File description:
** RegUtil.cpp
*/

#include "C4040.hpp"

nts::C4040::C4040()
{
    _nbPin = 16;
}

nts::C4040::~C4040()
{
}

nts::Tristate nts::C4040::getPin(size_t pin)
{
    switch (pin) {
        case 9:
            return _flipFlop_01->GetQ();
        case 7:
            return _flipFlop_02->GetQ();
        case 6:
            return _flipFlop_03->GetQ();
        case 5:
            return _flipFlop_04->GetQ();
        case 3:
            return _flipFlop_05->GetQ();
        case 2:
            return _flipFlop_06->GetQ();
        case 4:
            return _flipFlop_07->GetQ();
        case 13:
            return _flipFlop_08->GetQ();
        case 12:
            return _flipFlop_09->GetQ();
        case 14:
            return _flipFlop_10->GetQ();
        case 15:
            return _flipFlop_11->GetQ();
        case 1:
            return _flipFlop_12->GetQ();
        default:
            throw std::out_of_range("Pin out of range");
    }
    return UNDEFINED;
}


nts::Tristate nts::C4040::compute(size_t pin)
{
    ++_cycle;
    if (_cycle >= 1000) {
        reset();
        return getPin(pin);
    }
    Tristate cl_clock = _links[10]->compute(_linksPin[10]);
    Tristate in_reset = _links[11]->compute(_linksPin[11]);
    if (IS_UNDEFINED(cl_clock) || IS_UNDEFINED(in_reset))
        return UNDEFINED;
    Tristate data = Gate::Nor(Gate::Not(cl_clock), in_reset);
    Tristate clock = Gate::Not(data);
    Tristate set = Gate::Not(in_reset);
    _flipFlop_01->compute(clock, data, set);
    _flipFlop_02->compute(_flipFlop_01->GetQPrime(), _flipFlop_01->GetQ(), set);
    _flipFlop_03->compute(_flipFlop_02->GetQPrime(), _flipFlop_02->GetQ(), set);
    _flipFlop_04->compute(_flipFlop_03->GetQPrime(), _flipFlop_03->GetQ(), set);
    _flipFlop_05->compute(_flipFlop_04->GetQPrime(), _flipFlop_04->GetQ(), set);
    _flipFlop_06->compute(_flipFlop_05->GetQPrime(), _flipFlop_05->GetQ(), set);
    _flipFlop_07->compute(_flipFlop_06->GetQPrime(), _flipFlop_06->GetQ(), set);
    _flipFlop_08->compute(_flipFlop_07->GetQPrime(), _flipFlop_07->GetQ(), set);
    _flipFlop_09->compute(_flipFlop_08->GetQPrime(), _flipFlop_08->GetQ(), set);
    _flipFlop_10->compute(_flipFlop_09->GetQPrime(), _flipFlop_09->GetQ(), set);
    _flipFlop_11->compute(_flipFlop_10->GetQPrime(), _flipFlop_10->GetQ(), set);
    _flipFlop_12->compute(_flipFlop_11->GetQPrime(), _flipFlop_11->GetQ(), set);
    return getPin(pin);
}
