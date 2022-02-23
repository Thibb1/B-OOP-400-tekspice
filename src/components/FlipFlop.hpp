/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** FlipFlop
*/

#ifndef FLIPFLOP_HPP_
#define FLIPFLOP_HPP_

#include "Gate.hpp"

namespace nts {
    class FlipFlop {
        public:
            FlipFlop();
            ~FlipFlop();
            void compute(Tristate, Tristate, Tristate, Tristate);
            Tristate GetQ();
            Tristate GetQPrime();
        protected:
        private:
            Tristate _clock = UNDEFINED;
            Tristate _Q = UNDEFINED;
            Tristate _QPrime = UNDEFINED;
    };
}

#endif /* !FLIPFLOP_HPP_ */
