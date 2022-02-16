/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Compute
*/

#include "Compute.hpp"

void nts::Compute::Run(nts::Factory factory)
{
    int ticks = 0;
    std::cout << "> ";
    std::string line;
    while (getline(std::cin, line)) {
        if (RegUtils::isMatch(line, "^\\s*exit\\s*$"))
            break;
        if (RegUtils::isMatch(line, "^\\s*display\\s*$")) {
            std::cout
                << "tick: " << ticks << "\n"
                << "input(s):\n";
            

    }
}
