
#pragma once
#include "components.hpp"

namespace nts {

    class AComponent : public nts::IComponent
    {
    public:
        virtual ~AComponent() {}
        AComponent() {}
        virtual void simulate(std::size_t tick);
        virtual nts::Tristate compute(std::size_t pin);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin) {
            this->link[pin - 1] = std::make_pair(&other, otherPin);
        }
        virtual void dump() const;
        void setDefault (int it) {
            this->pin = new nts::Tristate[it];
            for (int i = 0; i < it; i++) {
                this->pin[i] = nts::Tristate::UNDEFINED;
                this->link.push_back(std::make_pair(nullptr, -1));
            }
        }
    protected:
        nts::Tristate *pin;
        std::vector<std::pair<nts::IComponent *, int>> link;
        std::string type;
    };
}