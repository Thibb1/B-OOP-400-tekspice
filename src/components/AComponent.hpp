/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** AComponent
*/

#pragma once

#include <map>
#include <vector>
#include <algorithm>
#include "IComponent.hpp"

namespace nts {
    size_t MAX_CYCLE = 10000;
    class AComponent : public IComponent {
        public:
            virtual ~AComponent() = default;

            virtual Tristate compute(size_t pin) = 0;
            virtual Tristate getPins(size_t pin);
            virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin);
            virtual void dump() const = 0;
            virtual void reset();
        protected:
            nts::Tristate _value = UNDEFINED;
            size_t _nbPin = 3;
            std::map<size_t, std::pair<size_t, IComponent &>> _links;
            size_t _cycle = 0;
    };
}