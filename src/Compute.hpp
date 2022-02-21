/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Compute
*/

#ifndef COMPUTE_HPP_
#define COMPUTE_HPP_

#include "Factory.hpp"
#include "RegUtils.hpp"

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

#endif /* !COMPUTE_HPP_ */
