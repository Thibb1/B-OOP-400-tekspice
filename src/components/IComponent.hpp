/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents
** File description:
** IComponent.hpp
*/

#pragma once

#include <iostream>

namespace nts {
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    class IComponent {
        public:
            virtual ~IComponent() = default;

            virtual void simulate(std::size_t tick) = 0;
            virtual Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual IComponent *clone() const = 0;
    };
    #define IS_UNDEFINED(nts) ((nts) == UNDEFINED)
}

