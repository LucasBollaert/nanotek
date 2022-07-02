#include "../../include/AComponent.hpp"

namespace nts {
    class  or4011 : public nts::AComponent
    {
    public:
        virtual ~or4011() {}
        or4011() {
            this->setDefault(14);
        }
        virtual nts::Tristate compute(std::size_t pin);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin);
        private:
    };
}