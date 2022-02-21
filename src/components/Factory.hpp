/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

// #pragma once

#include <string>
#include <map>
#include <memory>

#include "AComponent.hpp"
#include "chipsets/CInput.hpp"
#include "chipsets/COutput.hpp"

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory() = default;
            std::unique_ptr<IComponent> createComponent(const std::string &type);
            void AddChipset(const std::string &name, std::string const &key);
            IComponent *GetChipset(const std::string &name);
            std::map<std::string, IComponent *> GetChipsets();
        protected:
        private:
            std::map<std::string, IComponent *> _chipsetFactory;
            std::map<std::string, IComponent *> _chipsets;
    };
}

#endif /* !FACTORY_HPP_ */
