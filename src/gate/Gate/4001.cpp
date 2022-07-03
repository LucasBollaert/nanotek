/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-Bollaert.Lucas
** File description:
** AComponent.hpp
*/

#include "../include/4001.hpp"

nts::4001::4001() {

}

nts::4001::~4001(){

}

void nts::4001::simulate(std::size_t tick){
    std::cout << "nts::4001::simulate dans 4001.cpp" << std::endl;
}

void nts::4001::dump() const{
    std::cout << "nts::4001::Dump dans 4001.cpp" << std::endl;
}

nts::Tristate nts::4001::compute(std::size_t pin)
{
    switch (pin) {
        case 3:
            if (this->compute(1) == nts::Tristate::FALSE && 
                this->compute(2) == nts::Tristate::FALSE)
                return (nts::Tristate::TRUE);
            else
                return (nts::Tristate::FALSE);
            break;
        case 4:
            if (this->compute(5) == nts::Tristate::FALSE && 
                this->compute(6) == nts::Tristate::FALSE)
                return (nts::Tristate::TRUE);
            else
                return (nts::Tristate::FALSE);
            break;
        case 10:
            if (this->compute(9) == nts::Tristate::FALSE && 
                this->compute(8) == nts::Tristate::FALSE)
                return (nts::Tristate::TRUE);
            else
                return (nts::Tristate::FALSE);
            break;
        case 11:
            if (this->compute(12) == nts::Tristate::FALSE && 
                this->compute(13) == nts::Tristate::FALSE)
                return (nts::Tristate::TRUE);
            else
                return (nts::Tristate::FALSE);
            break;
    }
    if (this->link[pin -1].first == nullptr)
        return (nts::Tristate::UNDEFINED);
    else
        return (this->link[pin -1].first->compute(this->link[pin -1].second));
}