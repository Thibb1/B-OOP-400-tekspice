/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
    _chipsetFactory["input"] = new CInput();
    _chipsetFactory["output"] = new COutput();
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    if (_chipsetFactory.find(type) == _chipsetFactory.end())
        throw std::runtime_error("No chipset constructor with this name");
    return std::unique_ptr<IComponent>(_chipsetFactory[type]->clone());
}

void nts::Factory::AddChipset(const std::string &name, std::string const &key)
{
    _chipsets[name] = std::move(createComponent(key)).get();
}

nts::IComponent *nts::Factory::GetChipset(const std::string &name)
{
    if (_chipsets.find(name) == _chipsets.end())
        throw std::runtime_error("Chipset not found");
    return _chipsets[name];
}

std::map<std::string, nts::IComponent *> nts::Factory::GetChipsets()
{
    return _chipsets;
}