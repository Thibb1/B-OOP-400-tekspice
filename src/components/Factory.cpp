/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
    AddComponent("input", "C_INPUT");
    AddComponent("output", "C_OUTPUT");
    AddComponent("2716", "C_2716");
    AddComponent("4001", "C_4001");
    AddComponent("4008", "C_4008");
    AddComponent("4011", "C_4011");
    AddComponent("4013", "C_4013");
    AddComponent("4017", "C_4017");
    AddComponent("4930", "C_4930");
    AddComponent("4040", "C_4040");
    AddComponent("4069", "C_4069");
    AddComponent("4071", "C_4071");
    AddComponent("4081", "C_4081");
    AddComponent("4094", "C_4094");
    AddComponent("4512", "C_4512");
    AddComponent("4514", "C_4514");
    AddComponent("4801", "C_4801");
    AddComponent("bad", "C_BAD");
    AddComponent("clock", "C_CLOCK");
    AddComponent("false", "C_FALSE");
    AddComponent("input_output", "C_INPUT_OUTPUT");
    AddComponent("logger", "C_LOGGER");
    AddComponent("true", "C_TRUE");
    AddComponent("altered-counter", "C_ALTERED_COUNTER");
    AddComponent("and-or-not", "C_AND_OR_NOT");
    AddComponent("and", "C_AND");
}

void nts::Factory::AddComponent(std::string const &type, std::string const &value)
{
    _components[type] = std::make_unique<AComponent>(value);
}