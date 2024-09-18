#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    *this = other;
}

Intern& Intern::operator=(const Intern& other) {
    if (this != &other) {
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[3] = {"shrubbery creation", "presidential pardon", "robotomy request"};
    AForm* (Intern::*creators[3])(const std::string&) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createPresidentialPardonForm,
        &Intern::createRobotomyRequestForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*creators[i])(target);
        }
    }
    std::cerr << "Error: Form \"" << formName << "\" does not exist." << std::endl;
    return NULL;
}
