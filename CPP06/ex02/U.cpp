#include <cstdlib>
#include <ctime>
#include <iostream>
#include "U.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Generate a random Base* which could be A, B, or C
Base* generate(void) {
    int random = rand() % 3;
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL;
}

// Identify using a pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identify using a reference (no pointer)
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } catch (...) {
        std::cout << "Unknown type" << std::endl;
    }
}
