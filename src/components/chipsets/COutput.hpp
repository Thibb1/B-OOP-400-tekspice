/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** COutput
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class COutput : public AComponent {
        public:
            COutput();
            ~COutput();
            Tristate compute(size_t pin = 1);
            void simulate(std::size_t tick);
            COutput *clone() const;
            void dump() const override;
        protected:
        private:
    };
}
