/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
** File description:
** Main.cpp
*/

#include <fstream>
#include <sstream>
#include <string.h>
#include <iostream>
#include <vector>
#include "shell.hpp"
#include "config.hpp"

void parseString(const std::string s, std::string delim)
{
    std::string argument;
    int n = 0;

    auto start = 0U;
    auto end = s.find(delim);
    while (end != std::string::npos)
    {
        argument = s.substr(start, end - start);
        //std::cout << "n = " << n << " & argument = " << argument << std::endl;
        if (argument[0] == '#')
            n = 0;
        else if (argument == ".chipsets:")
            n = 1;
        else if (argument == ".links:")
            n = 2;
        else {
            if (n == 1)
                Chipsets chip(argument); //save argument to class chipsets
            else if (n == 2)
                n=2;
                //Links link(argument); //save argument to class links
            else {
                std::cerr << "Invalid argument: " + argument << std::endl;
            }
        }
        start = end + delim.length();
        end = s.find(delim, start);
    }
}

std::string readFileContent(const std::string &file)
{
    std::ifstream t(file);
    if (t) {
        std::stringstream buffer;
        buffer << t.rdbuf();
        return buffer.str();
    }
    else {
        return ("ERROR file: " + file + " is not a valid filename.");
    }
}

void checkInput(std::string input)
{
    if (input == "display")
        std::cout << "using display function" << std::endl;
    else if (input == "value=")
        std::cout << "using new value function" << std::endl;
    else if (input == "simulate")
        std::cout << "using simulate function" << std::endl;
    else if (input == "loop")
        std::cout << "entering loop function" << std::endl;
    else if (input == "dump")
        std::cout << "using dump function" << std::endl;
    else
        std::cout << input << ": unknown command" << std::endl;
}

int main(int argc, char **argv)
{
    std::string content;
	int ret = 0;
    std::cout << argc << std::endl;
    if (argc != 2) return 84;
    else {
        parseString((content = readFileContent(argv[1])), "\n");
		Shell sh;
        while (ret == 0)
            ret = sh.GetCommand();
    }
    if (ret == 1)
        return (0);
    return (ret);
}