#include "../include/AComponent.hpp"
#include "gateInclude/4011.hpp"

nts::Tristate nts::or4011::compute(std::size_t pin)
{
    switch (pin) {
        case 3:
            if ((this->compute(1) == nts::Tristate::TRUE && 
                this->compute(2) == nts::Tristate::TRUE) ||
                (this->compute(1) == nts::Tristate::TRUE && 
                this->compute(2) == nts::Tristate::TRUE))
                return (nts::Tristate::FALSE);
            else
                return (nts::Tristate::TRUE);
            break;
        case 4:
            if ((this->compute(5) == nts::Tristate::TRUE && 
                this->compute(6) == nts::Tristate::TRUE) ||
                (this->compute(5) == nts::Tristate::TRUE && 
                this->compute(6) == nts::Tristate::TRUE))
                return (nts::Tristate::FALSE);
            else
                return (nts::Tristate::TRUE);
            break;
        case 10:
            if ((this->compute(9) == nts::Tristate::TRUE && 
                this->compute(8) == nts::Tristate::TRUE) ||
                (this->compute(9) == nts::Tristate::TRUE && 
                this->compute(8) == nts::Tristate::TRUE))
                return (nts::Tristate::FALSE);
            else
                return (nts::Tristate::TRUE);
            break;
        case 11:
            if ((this->compute(12) == nts::Tristate::TRUE && 
                this->compute(13) == nts::Tristate::TRUE) ||
                (this->compute(12) == nts::Tristate::TRUE && 
                this->compute(13) == nts::Tristate::TRUE))
                return (nts::Tristate::FALSE);
            else
                return (nts::Tristate::TRUE);
            break;
    }
    if (this->link[pin -1].first == nullptr)
        return (nts::Tristate::UNDEFINED);
    else
        return (this->link[pin -1].first->compute(this->link[pin -1].second));
}