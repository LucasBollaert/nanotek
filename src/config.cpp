/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
** File description:
** Configs.cpp
*/

#include <map>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <vector>
#include "config.hpp"

Chipsets::Chipsets(std::string s)
{
    std::string delim = " ";
    std::string argument;

    auto start = 0U;
    auto end = s.find(delim);
    std::string type = s.substr(start, end - start);
    start = end + delim.length();
    end = s.find(delim, start);
    std::string name = s.substr(start, end - start);
    this->name = name;
    if (type == "input")
        this->type = INPUT;
    else if (type == "output")
        this->type = OUTPUT;
    else if (type == "clock")
        this->type = CLOCK;
    else if (type == "true")
        this->type = TRUE;
    else if (type == "false")
        this->type = FALSE;
    else {
        try {
            std::stoi(type);
        }
        catch (const std::invalid_argument& ia) {
            std::cerr << "Invalid argument: " << type << '\n';
            exit(84);
        }
        this->type = COMPONENT;
    }
}

Links::Links(std::string s)
{
    std::cout << "Links funvtion class: " << std::endl;
    std::string delim = " ";
    std::string argument;

    auto start = 0U;
    auto end = s.find(delim);
    std::string left = s.substr(start, end - start);
    start = end + delim.length();
    end = s.find(delim, start);
    std::string right = s.substr(start, end - start);
    this->left = left;
    this->right = right;   
}

/*
std::map<std::size_t, std::pair<std::size_t, nts::IComponent *> > links;
void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    this->links.insert(std::make_pair(pin, std::make_pair(otherPin, &other)));
}
*/