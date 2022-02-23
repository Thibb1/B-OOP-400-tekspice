/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4030 : public AComponent {
        public:
            C4030();
            ~C4030();
            Tristate compute(size_t pin = 1);
            void simulate(size_t tick);
        protected:
        private:
    };
}

#endif /* !C4030_HPP_ */
