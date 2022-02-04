/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** main
*/

#include <iostream>
#include <regex>
#include "src/utils/RegUtils.hpp"
#include "src/parser/Parser.hpp"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    try {
        std::cout << "Test 1: " << std::endl;
        Parser::parse("asset/B-OOP-400_nanotekspicezip/nts_single/2716_rom.nts");
        std::cout << "Test 2: " << std::endl;
        Parser::parse("asset/B-OOP-400_nanotekspicezip/nts_single/4081_and.nts");
        std::cout << "Test 3: " << std::endl;
        Parser::parse("asset/B-OOP-400_nanotekspicezip/nts_single/bad.nts");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}