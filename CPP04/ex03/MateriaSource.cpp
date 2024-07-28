#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        templates[i] = NULL;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete templates[i];
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        templates[i] = other.templates[i] ? other.templates[i]->clone() : NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete templates[i];
            templates[i] = other.templates[i] ? other.templates[i]->clone() : NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (!templates[i]) {
            templates[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
    for (int i = 0; i < 4; ++i) {
        if (templates[i] && templates[i]->getType() == type) {
            return templates[i]->clone();
        }
    }
    return 0;
}
