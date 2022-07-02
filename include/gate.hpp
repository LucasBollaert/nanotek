#pragma once
#include "components.hpp"

namespace nts {
    class gate:IComponent
    {
    public:
        virtual ~gate() = default;
        gate() {}
        nts::Tristate myXOR(nts::Tristate a, nts::Tristate b);
        nts::Tristate myNOR(nts::Tristate a, nts::Tristate b);
        nts::Tristate myOR(nts::Tristate a, nts::Tristate b);
        nts::Tristate myAND(nts::Tristate a, nts::Tristate b);
        nts::Tristate myNAND(nts::Tristate a, nts::Tristate b);
        nts::Tristate myINVERTER(nts::Tristate a);
        nts::Tristate my_4008();

    private:
       
    };
}