/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4001_HPP_
#define C4001_HPP_

#include "AComponent.hpp"
namespace nts {

    class C4001 : public AComponent {
        public:
            C4001();
            ~C4001();
        Tristate compute(size_t pin = 1);
        void simulate(size_t tick);

        protected:
        private:
    };
}

#endif /* !C4001_HPP_ */
