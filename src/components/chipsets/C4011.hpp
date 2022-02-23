/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4011_HPP_
#define C4011_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4011 : public AComponent {
        public:
            C4011();
            ~C4011();
            Tristate compute(size_t pin = 1);
            void simulate(size_t tick);
        protected:
        private:
    };
}

#endif /* !C4011_HPP_ */
