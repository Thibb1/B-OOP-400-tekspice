/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
    _chipsetFactory["input"] = std::unique_ptr<IComponent>(new CInput());
    _chipsetFactory["output"] = std::unique_ptr<IComponent>(new COutput());
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    auto chipset = _chipsetFactory.find(type);
    if (chipset == _chipsetFactory.end())
        throw std::runtime_error("No chipset constructor with this name");
    return std::unique_ptr<IComponent>(chipset->second->clone());
}

void nts::Factory::AddChipset(const std::string &name, std::string const &key)
{
    _chipsets[name] = createComponent(key);
}

std::shared_ptr<nts::IComponent> nts::Factory::GetChipset(const std::string &name)
{
    auto chipset = _chipsets.find(name);
    if (chipset == _chipsets.end())
        throw std::runtime_error("Chipset not found");
    return chipset->second;
}

std::map<std::string, std::shared_ptr<nts::IComponent>> nts::Factory::GetChipsets()
{
    return _chipsets;
}