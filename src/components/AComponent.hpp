/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include <map>
#include <vector>
#include <algorithm>
#include "IComponent.hpp"

namespace nts {
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
            std::map<size_t, IComponent *> _links;
            std::map<size_t, size_t> _linksPin;
            size_t _cycle = 0;
    };
}

#endif /* !ACOMPONENT_HPP_ */