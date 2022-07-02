/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
** File description:
** components.hpp
*/

#include <iostream>
#include "AComponent.hpp"
#include <vector>
#pragma once

namespace nts
{
    enum Tristate {
    UNDEFINED = (-true),
    TRUE = true,
    FALSE = false
    };

    class IComponent
    {
    public :
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin) = 0;
        virtual void dump() const = 0;
    };
}