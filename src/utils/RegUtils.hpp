/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** RegUtil.hpp
*/

#pragma once

#include <string>
#include <regex>

class RegUtils {
    public:
        RegUtils() = default;
        ~RegUtils() = default;
        static bool isMatch(std::string const &str, std::string const &pattern);
        static std::smatch getMatch(std::string const &str, std::string const &pattern);
    protected:
    private:
};
