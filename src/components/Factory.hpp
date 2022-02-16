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

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory() = default;
            void AddComponent(std::string const &type, std::string const &value);
            nts::AComponent GetComponent(std::string const &type);
        protected:
        private:
            std::map<std::string, std::unique_ptr<AComponent>> _components;
    };
}
