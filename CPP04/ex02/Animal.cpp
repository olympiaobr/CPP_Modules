#include "Animal.hpp"

Animal::Animal() : type("Generic Animal") {
    std::cout << "Animal constructor called." << std::endl;
}

Animal::Animal(const Animal& other) {
    *this = other;
    std::cout << "Animal copy constructor called." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructor called." << std::endl;
}

std::string Animal::getType() const {
    return type;
}
