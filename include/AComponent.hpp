/*
** EPITECH PROJECT, 2021
** B-OOP-400-BRU-4-1-tekspice-Bollaert.Lucas
** File description:
** AComponent.hpp
*/

#include "IComponents.hpp"

namespace nts {
    class AComponent : IComponent 
    {
        public:
            AComponent() {};
            virtual ~AComponent() = default;
        protected:
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void dump() const = 0;
            
            void setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin) {
                this->link[pin - 1] = std::make_pair(&other, otherPin);
            };

            void setDefault (int it) {
                this->pin = new nts::Tristate[it];
                for (int i = 0; i < it; i++) {
                    this->pin[i] = nts::Tristate::UNDEFINED;
                    this->link.push_back(std::make_pair(nullptr, -1));
                }
            }
    }
}