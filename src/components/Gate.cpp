/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Gate
*/

#include "Gate.hpp"

nts::Tristate nts::Gate::Not(Tristate a)
{
    if (IS_UNDEFINED(a))
        return UNDEFINED;
    return (a == TRUE) ? FALSE : TRUE;
}

nts::Tristate nts::Gate::Or(Tristate a, Tristate b)
{
    if (IS_UNDEFINED(a) || IS_UNDEFINED(b))
        return UNDEFINED;
    return (a == TRUE || b == TRUE) ? TRUE : FALSE;
}

nts::Tristate nts::Gate::Nor(Tristate a, Tristate b)
{
    return Not(Or(a, b));
}

nts::Tristate nts::Gate::And(Tristate a, Tristate b)
{
    if (IS_UNDEFINED(a) || IS_UNDEFINED(b))
        return UNDEFINED;
    return (a == TRUE && b == TRUE) ? TRUE : FALSE;
}

nts::Tristate nts::Gate::Xor(Tristate a, Tristate b)
{
    if (IS_UNDEFINED(a) || IS_UNDEFINED(b))
        return UNDEFINED;
    return (a == b) ? FALSE : TRUE;
}

nts::Tristate nts::Gate::Nand(Tristate a, Tristate b)
{
    return Not(And(a, b));
}