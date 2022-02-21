/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Compute
*/

#include "Compute.hpp"

void nts::Compute::Display(nts::Factory factory, std::size_t ticks)
{
    (void) factory;
    (void) ticks;
    // auto chipsets = factory.GetChipsets();
    // std::map<std::string, IComponent *> inputs;
    // std::map<std::string, IComponent *> output;
    // for (auto &chip : chipsets) {
    //     if (dynamic_cast<CInput *>(chip.second)) {
    //         inputs[chip.first] = chip.second;
    //     }
    //     if (dynamic_cast<COutput *>(chip.second)) {
    //         output[chip.first] = chip.second;
    //     }
    // }
    // std::cout
    //     << "tick: " << ticks << "\n"
    //     << "input(s):\n";
    // for (auto &input : inputs) {
    //     std::cout << input.first << ": ";
    //     input.second->dump();
    // }
    // std::cout
    //     << "output(s):\n";
    // for (auto &output : output) {
    //     std::cout << output.first << ": ";
    //     output.second->dump();
    // }
}

void nts::Compute::Run(nts::Factory factory)
{
    std::size_t ticks = 0;
    std::cout << "> ";
    std::string line;
    while (getline(std::cin, line)) {
        if (RegUtils::isMatch(line, "^\\s*exit\\s*$"))
            break;
        if (RegUtils::isMatch(line, "^\\s*display\\s*$")) {
            Display(factory, ticks);
            continue;
        }
        break;
    }
}