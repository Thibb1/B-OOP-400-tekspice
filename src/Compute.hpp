/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Compute
*/

#pragma once

#include "components/Factory.hpp"
#include "utils/RegUtils.hpp"

namespace nts {
    class Compute {
        public:
            Compute() = default;
            ~Compute() = default;
            static void Run(Factory);
            static void Display(Factory, std::size_t);
        protected:
        private:
    };
}
