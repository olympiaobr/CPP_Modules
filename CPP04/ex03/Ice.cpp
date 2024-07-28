#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& other) : AMateria(other) {}

Ice& Ice::operator=(const Ice& other) {
    AMateria::operator=(other);
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

Ice::~Ice( void ) {
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots ice bolt at " << target.getName() << " *" << std::endl;
}
