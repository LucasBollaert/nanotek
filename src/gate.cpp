/*
** EPITECH PROJECT, 2022
** B-OOP-400-BRU-4-1-tekspice-guillaume.janssens [WSL: Ubuntu-20.04]
** File description:
** Gate.cpp
*/

#include "components.hpp"
#include <bits/stdc++.h>

nts::Tristate myXOR(nts::Tristate a, nts::Tristate b)
{
    if (a == nts::Tristate::UNDEFINED || b == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    if ((a == nts::Tristate::TRUE && b == nts::Tristate::FALSE) || 
        (a == nts::Tristate::FALSE && b == nts::Tristate::TRUE))
        return (nts::Tristate::TRUE);
    return (nts::Tristate::FALSE);
}

nts::Tristate myNOR(nts::Tristate a, nts::Tristate b)
{
    if ((a == nts::Tristate::UNDEFINED && b == nts::Tristate::FALSE) ||
        (a == nts::Tristate::FALSE && b == nts::Tristate::UNDEFINED) ||
        (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED))
        return (nts::Tristate::UNDEFINED);

    if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    
    return (nts::Tristate::FALSE);
}

nts::Tristate myOR(nts::Tristate a, nts::Tristate b)
{
    if ((a == nts::Tristate::UNDEFINED && b == nts::Tristate::FALSE) ||
        (a == nts::Tristate::FALSE && b == nts::Tristate::UNDEFINED) ||
        (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED))
        return (nts::Tristate::UNDEFINED);
    if (a == nts::Tristate::TRUE || b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    return (nts::Tristate::FALSE);
}

nts::Tristate myAND(nts::Tristate a, nts::Tristate b)
{
    if ((a == nts::Tristate::UNDEFINED && b == nts::Tristate::FALSE) ||
        (a == nts::Tristate::FALSE && b == nts::Tristate::UNDEFINED) ||
        (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED))
        return (nts::Tristate::UNDEFINED);
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE)
        return (nts::Tristate::TRUE);
    return (nts::Tristate::FALSE);
}

nts::Tristate myNAND(nts::Tristate a, nts::Tristate b)
{
    if ((a == nts::Tristate::UNDEFINED && b == nts::Tristate::TRUE) ||
        (a == nts::Tristate::TRUE && b == nts::Tristate::UNDEFINED) ||
        (a == nts::Tristate::UNDEFINED && b == nts::Tristate::UNDEFINED))
        return (nts::Tristate::UNDEFINED);

    if ((a == nts::Tristate::FALSE || b == nts::Tristate::FALSE) ||
        (a == nts::Tristate::TRUE && b == nts::Tristate::FALSE) ||
        (a == nts::Tristate::FALSE && b == nts::Tristate::TRUE))
        return (nts::Tristate::TRUE);
    
    return (nts::Tristate::FALSE);
}

nts::Tristate myINVERTER(nts::Tristate a)
{
    if (a == nts::Tristate::UNDEFINED)
        return (nts::Tristate::UNDEFINED);
    if (nts::Tristate::FALSE)
        return (nts::Tristate::TRUE);
    if (nts::Tristate::TRUE)
        return (nts::Tristate::FALSE);
}

nts::Tristate my_4008_Elem(nts::Tristate  a, nts::Tristate  b, nts::Tristate *c)
{
    //true true true ==  1 1
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE && *c == nts::Tristate::TRUE) {
        std::cout << "1";
        return (nts::Tristate::TRUE);
    }
    //true true false ==  1 0
    if (a == nts::Tristate::TRUE && b == nts::Tristate::TRUE && *c == nts::Tristate::FALSE) {
        std::cout << "0";
        *c = nts::Tristate::TRUE;
        return (nts::Tristate::FALSE);
    }
    // (true false || false true) && true == 1 0
    if (myXOR(a, b) == nts::Tristate::TRUE && *c == nts::Tristate::TRUE) {
        *c = nts::Tristate::TRUE;
        std::cout << "0";
        return (nts::Tristate::FALSE);
    }
    // (true false || false true) && false == 0 1
    //false false true 0 1
    if ((myXOR(a, b) == nts::Tristate::TRUE && *c == nts::Tristate::FALSE) || 
        (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE && *c == nts::Tristate::TRUE)) {
        *c = nts::Tristate::FALSE;
        std::cout << "1";
        return (nts::Tristate::TRUE);
    }
    //false false false == 0 0
    if (a == nts::Tristate::FALSE && b == nts::Tristate::FALSE && *c == nts::Tristate::FALSE) {
        std::cout << "0";
        return (nts::Tristate::FALSE);
    }
    std::cout << "poubelle" << std::endl;
}

nts::Tristate my_4008(nts::AComponent::compute)
{
    nts::Tristate a[4] = {nts::Tristate::TRUE, nts::Tristate::FALSE, nts::Tristate::FALSE, nts::Tristate::TRUE};
    nts::Tristate b[4] = {nts::Tristate::FALSE, nts::Tristate::TRUE, nts::Tristate::FALSE, nts::Tristate::TRUE};
    nts::Tristate c = nts::Tristate::FALSE;
    
    for (int i = 3; i > -1; i--) {
        /*if (c == nts::Tristate::TRUE) {
            std::cout << "la retenue est presente en " << i <<  std::endl;
        }*/
        my_4008_Elem(a[i], b[i], &c);
    }

    if (c == nts::Tristate::TRUE) {
        std::cout << "1";
    }
    std::cout << std::endl;
    /*
    if (nts::Tristate::TRUE == a)
        std::printf("result: ta mere c est TRUE\n");
    if (nts::Tristate::FALSE == a)
        std::printf("result: ta mere c est FALSE\n");
    if (nts::Tristate::UNDEFINED == a)
        std::printf("result: ta mere c est UNDIFINED\n");
	if (nts::Tristate::TRUE == c)
        std::printf("Carry: ta mere c est TRUE\n");
    if (nts::Tristate::FALSE == c)
        std::printf("Carry: ta mere c est FALSE\n");
*/
}

int main ()
{
    my_4008();
    //nts::Tristate a = myNAND(nts::Tristate::FALSE, nts::Tristate::UNDEFINED);
    return 0;
}
