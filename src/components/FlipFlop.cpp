/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** FlipFlop
*/

#include "FlipFlop.hpp"

nts::FlipFlop::FlipFlop()
{
}

nts::FlipFlop::~FlipFlop()
{
}

void nts::FlipFlop::compute(Tristate clock, Tristate data, Tristate set, Tristate reset)
{
    if (IS_UNDEFINED(clock) || IS_UNDEFINED(reset) || IS_UNDEFINED(set))
        return;
    Tristate current = _clock != TRUE ? clock : FALSE;
    _clock = clock;
    if (Gate::Xor(set, reset) == TRUE) {
        _Q = set;
        _QPrime = reset;
    } else if (Gate::Nor(set, reset) == TRUE) {
        _Q = TRUE;
        _QPrime = TRUE;
    } else {
        if (IS_UNDEFINED(data))
            return;
        _Q = current == TRUE ? data : _Q;
        _QPrime = current == TRUE ? Gate::Not(data) : _QPrime;
    }
}

nts::Tristate nts::FlipFlop::GetQ()
{
    return _Q;
}

nts::Tristate nts::FlipFlop::GetQPrime()
{
    return _QPrime;
}
