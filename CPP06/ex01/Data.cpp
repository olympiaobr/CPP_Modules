#include "Data.hpp"
#include <iostream>

// Default constructor
Data::Data() : id(0), name("Default") {
    std::cout << "Data Default Constructor Called" << std::endl;
}

// Copy constructor
Data::Data(const Data &other) : id(other.id), name(other.name) {
    std::cout << "Data Copy Constructor Called" << std::endl;
}

// Assignment operator
Data &Data::operator=(const Data &other) {
    if (this != &other) {
        id = other.id;
        name = other.name;
    }
    std::cout << "Data Assignment Operator Called" << std::endl;
    return *this;
}

// Destructor
Data::~Data() {
    std::cout << "Data Destructor Called" << std::endl;
}
