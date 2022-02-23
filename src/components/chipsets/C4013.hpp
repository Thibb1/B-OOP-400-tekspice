/*
** EPITECH PROJECT, 2022
** NanoTekSpace
** File description:
** C4001
*/

#ifndef C4013_HPP_
#define C4013_HPP_

#include "AComponent.hpp"

namespace nts {

    class C4013 : public AComponent {
        public:
            C4013();
            ~C4013();
            Tristate compute(size_t pin = 1);
        protected:
        private:
    };
}

#endif /* !C4013_HPP_ */
