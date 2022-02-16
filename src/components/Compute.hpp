/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Compute
*/

#pragma once

#include "Factory.hpp"
#include "../utils/RegUtils.hpp"

namespace nts {
    class Compute {
        public:
            Compute() = default;
            ~Compute() = default;
            static void Run(nts::Factory factory);
        protected:
        private:
    };
}
