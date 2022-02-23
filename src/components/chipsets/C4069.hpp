/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "AComponent.hpp"

namespace nts {
    class C4069 : public AComponent {
        public:
            C4069();
            ~C4069();
            Tristate compute(size_t pin = 1);
        protected:
        private:
    };
}

#endif /* !C4069_HPP_ */
