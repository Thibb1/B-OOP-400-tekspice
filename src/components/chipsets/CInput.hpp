/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Input
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class CInput : public AComponent {
        public:
            CInput();
            ~CInput();
            Tristate compute(size_t pin = 1);
            void simulate(std::size_t tick);
            CInput *clone() const;
            void dump() const override;
        protected:
        private:
    };
}
