#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::fill_n(ideas, 100, "Empty Idea");
    std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(const Brain& other) {
    *this = other;
    std::cout << "Brain copy constructed" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        std::copy(other.ideas, other.ideas + 100, ideas);
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructed" << std::endl;
}
