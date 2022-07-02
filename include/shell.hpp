/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
** File description:
** shell.hpp
*/

#pragma once

#include <fstream>
#include <sstream>
#include <string.h>
#include <iostream>

class Shell 
{
public:
    Shell() = default;
    ~Shell() = default;

    int GetCommand(void);
private:
    std::string command;
};