#include "../../include/AComponent.hpp"

namespace nts {

    class  or4001 : public nts::AComponent
    {
    public:
        virtual ~or4001() {}
        or4001() {
            this->setDefault(14);
        }
        virtual nts::Tristate compute(std::size_t pin);
        virtual void setLink(std::size_t pin, nts::IComponent &other, std:: size_t otherPin);
        private:
    };
}