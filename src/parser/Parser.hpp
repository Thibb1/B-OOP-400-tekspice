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

#include "../utils/RegUtils.hpp"

class Parser {
    public:
        Parser() = default;
        ~Parser() = default;
        static void parse(std::string filename);
        static std::ifstream checkFile(std::string filename);
        static bool isInVector(std::string str, std::vector<std::string> vec);
    protected:
    private:
};
