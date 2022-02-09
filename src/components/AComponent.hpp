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
    class AComponent : public nts::IComponent {
        public:
            virtual ~AComponent() = default;

            virtual nts::Tristate compute(size_t pin) = 0;
            virtual nts::Tristate getPins(size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual void reset() = 0;
        protected:
            nts::Tristate _value = nts::UNDEFINED;
            size_t _nbPin = 3;
            std::map<size_t, std::pair<size_t, nts::IComponent *>> _link;
            size_t _cycle = 0;
    };
}