#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "Cat constructor called." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat() {
    delete brain;
    std::cout << "Cat destructor called." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}

void Cat::changeIdea(int index, const std::string& idea) {
    if (index >= 0 && index < 100) {
        brain->ideas[index] = idea;
    }
}

std::string Cat::getIdea(int index) const {
    if (index >= 0 && index < 100) {
        return brain->ideas[index];
    }
    return "Index out of bounds";
}
