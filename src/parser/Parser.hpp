/*
** EPITECH PROJECT, 2022
** /home/hugo/Epitech/tekspice
** File description:
** RegUtil.hpp
*/

#pragma once

#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

#include <iostream>

#include "../utils/RegUtils.hpp"
#include "../components/Factory.hpp"

class Parser {
    public:
        Parser() = default;
        ~Parser() = default;
        static void parse(std::string, nts::Factory);
        static std::ifstream checkFile(std::string);
        static bool isInVector(std::string, std::vector<std::string>);
    protected:
    private:
};
