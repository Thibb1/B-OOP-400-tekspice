/*
** EPITECH PROJECT, 2022
** /home/thibb1/Documents/tekspice
** File description:
** Factory.cpp
*/

#include "Factory.hpp"

nts::Factory::Factory()
{
    _chipsetFactory["input"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CInput>(); };
    _chipsetFactory["output"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<COutput>(); };
    _chipsetFactory["clock"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CClock>(); };
    _chipsetFactory["false"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CFalse>(); };
    _chipsetFactory["true"] = []()->std::unique_ptr<nts::IComponent> { return std::make_unique<CTrue>(); };
}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type)
{
    if (_chipsetFactory.find(type) == _chipsetFactory.end())
        throw std::runtime_error("Unknown chipset");
    return std::move(_chipsetFactory[type]());
}

void nts::Factory::AddChipset(const std::string &name, std::string const &key)
{
    _chipsets[name] = createComponent(key);
    _chipsetsTypes[name] = key;
}

nts::IComponent *nts::Factory::GetChipset(const std::string &name)
{
    if (_chipsets.find(name) == _chipsets.end())
        throw std::runtime_error("Chipset not found");
    return _chipsets[name].get();
}

std::map<std::string, std::string> nts::Factory::GetChipsetsTypes()
{
    return _chipsetsTypes;
}