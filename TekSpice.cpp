/*
** EPITECH PROJECT, 2022
** Documents
** File description:
** main
*/

#include <iostream>
#include <regex>
#include "src/utils/RegUtils.hpp"

int main(int ac, char **av)
{
    (void) ac;
    (void) av;
    try {
        if (RegUtils::isMatch("output out_04", "^output out_(\\d{2})$")) {
            std::cout << RegUtils::getMatch("output out_04", "^output out_(\\d{2})$")[1].str() << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}