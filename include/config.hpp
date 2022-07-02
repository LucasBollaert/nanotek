/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
** File description:
** Chipsets.hpp
*/

#pragma once

#include <vector>
#include <iostream>

enum type {INPUT, CLOCK, TRUE, FALSE, OUTPUT, COMPONENT};

class Chipsets
{
public:
    Chipsets() = default;
    Chipsets(std::string s);
    ~Chipsets() {}

private:
    std::string name;
    enum type type;
};

class Links
{
public:
    Links(std::string s);
    ~Links() {}
private:
    int index;
    std::string left;
    std::string right;
};