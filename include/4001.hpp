/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-Bollaert.Lucas
** File description:
** 4001.hpp
*/

#include "AComponent.hpp"

namespace nts {
    class 4001 : IComponent 
    {
        public:
            4001();
            virtual ~4001();
        protected:
            void simulate(std::size_t tick);
            nts::Tristate compute(std::size_t pin);
            void dump() const;
    }
}