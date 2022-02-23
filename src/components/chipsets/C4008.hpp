/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4008 : public AComponent {
        public:
            C4008();
            ~C4008();
            Tristate compute(size_t pin = 1);
            void simulate(size_t tick);
            Tristate computeSum(Tristate, Tristate, Tristate);
            Tristate computeComp(Tristate, Tristate, Tristate);
        protected:
        private:
    };
}

#endif /* !C4008_HPP_ */
