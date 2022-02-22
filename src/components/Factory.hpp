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
#include <functional>

#include "AComponent.hpp"
#include "CInput.hpp"
#include "COutput.hpp"
#include "CClock.hpp"
#include "CFalse.hpp"
#include "CTrue.hpp"

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory() = default;
            std::unique_ptr<IComponent> createComponent(const std::string &type);
            void AddChipset(const std::string &name, std::string const &key);
            nts::IComponent *GetChipset(const std::string &name);
            std::map<std::string, std::string> GetChipsetsTypes();
        protected:
        private:
            std::map<std::string, std::function<std::unique_ptr<IComponent>()>> _chipsetFactory;
            std::map<std::string, std::unique_ptr<IComponent>> _chipsets;
            std::map<std::string, std::string> _chipsetsTypes;
            std::unique_ptr<IComponent> createCInput() const;
            std::unique_ptr<IComponent> createCOutput() const;
    };
}

#endif /* !FACTORY_HPP_ */
