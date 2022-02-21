/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** main
*/

#include "Tekspice.hpp"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    try {
        nts::Factory factory;
        std::cout << "Test 1: " << std::endl;
        Parser::parse(
            // "asset/B-OOP-400_nanotekspicezip/nts_single/2716_rom.nts",
            "test.nts",
            factory
        );
        nts::Compute::Run(factory);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}