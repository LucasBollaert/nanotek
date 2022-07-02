/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
** File description:
** shell.cpp
*/

#include "shell.hpp"

int Shell::GetCommand()
{
	std::string input;
	std::cout << "> ";
  	std::getline(std::cin, input);
      this->command = input;
    if (input == "\0" || input == "exit") {
        this->command = "exit";
        return 1;
    }
    //else {
    //    checkInput(input);
    //}
    return 0;
}