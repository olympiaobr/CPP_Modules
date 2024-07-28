#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria(std::string const & type) : type(type)
{
    std::cout << "AMateria created with type: " << type << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
    std::cout << "AMateria copied with type: " << type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

AMateria::~AMateria() {
    std::cout << "AMateria of type " << type << " destroyed." << std::endl;
}

std::string const & AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter& target) {
    std::cout << "Using AMateria on " << target.getName() << std::endl;
}
