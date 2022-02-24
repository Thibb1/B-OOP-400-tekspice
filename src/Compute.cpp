/*
** EPITECH PROJECT, 2022
** tekspice
** File description:
** Compute
*/

#include "Compute.hpp"

static bool _looping = false;

nts::Compute::Compute(nts::Factory *factory) : _ticks(0)
{
    _chipsets = factory->GetChipsetsTypes();
    for (auto &it : _chipsets) {
        if (RegUtils::isMatch(it.second, "^input$|^clock$")) {
            _inputs[it.first] = factory->GetChipset(it.first);
        }
        if (RegUtils::isMatch(it.second, "^output$")) {
            _outputs[it.first] = factory->GetChipset(it.first);
        }
    }
}

void nts::Compute::Display()
{
    std::cout << "tick: " << _ticks << "\ninput(s):\n";
    for (auto &input : _inputs) {
        std::cout << "  " << input.first << ": ";
        input.second->dump();
    }
    std::cout << "output(s):\n";
    for (auto &output : _outputs) {
        std::cout << "  " << output.first << ": ";
        output.second->dump();
    }
}

void nts::Compute::Simulate()
{
    ++_ticks;
    for (auto &input : _inputs) {
        input.second->simulate(_ticks);
    }
    auto values_it = _values;
    for (auto &new_val : values_it) {
        _inputs[new_val.first]->setValue(new_val.second);
        _values.erase(new_val.first);
    }
    for (auto &output : _outputs) {
        output.second->simulate(1);
        output.second->reset();
    }
}

void nts::Compute::AddChange(std::string const &str)
{
    std::smatch smatch = RegUtils::getMatch(str, "^(\\w+)=(1|0|U)$");
    if (_inputs.find(smatch[1]) != _inputs.end()) {
        _values[smatch[1]] = GET_TRISTATE(smatch[2]);
    }
}

void nts::Compute::StopSignal(int signal)
{
    if (signal == SIGINT) {
        _looping = 0;
    }
}

void nts::Compute::Loop()
{
    _looping = 1;
    std::signal(SIGINT, &Compute::StopSignal);
    while (_looping) {
        Simulate();
        Display();
    }
}

void nts::Compute::Run()
{
    std::cout << "> ";
    std::string line;
    while (getline(std::cin, line)) {
        line = RegUtils::removeSpaces(line);
        if (RegUtils::isMatch(line, "^exit$"))
            break;
        if (RegUtils::isMatch(line, "^display$")) {
            Display();
        }
        if (RegUtils::isMatch(line, "^(\\w+)=(1|0|U)$")) {
            AddChange(line);
        }
        if (RegUtils::isMatch(line, "^simulate$")) {
            Simulate();
        }
        if (RegUtils::isMatch(line, "^loop$")) {
            Loop();
        }
        std::cout << "> ";
    }
}