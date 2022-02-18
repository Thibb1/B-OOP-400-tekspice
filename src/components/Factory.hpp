/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** Factory.hpp
*/

#pragma once

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
            std::shared_ptr<nts::IComponent> GetChipset(const std::string &name);
            std::map<std::string, std::shared_ptr<IComponent>> GetChipsets();
        protected:
        private:
            std::map<std::string, std::unique_ptr<IComponent>> _chipsetFactory;
            std::map<std::string, std::shared_ptr<IComponent>> _chipsets;
    };
}
