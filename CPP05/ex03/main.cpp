#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

int main() {
    try {
        Intern intern;
        AForm* form;

        form = intern.makeForm("robotomy request", "Bender");
        if (form) {
            std::cout << *form << std::endl;
            Bureaucrat bureaucrat("John", 1);
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form;
        } else {
            std::cerr << "Failed to create form." << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Intern intern;
        AForm* form;

        form = intern.makeForm("presidential pardon", "Alice");
        if (form) {
            std::cout << *form << std::endl;
            Bureaucrat bureaucrat("John", 1);
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form;
        } else {
            std::cerr << "Failed to create form." << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Intern intern;
        AForm* form;

        form = intern.makeForm("shrubbery creation", "Home");
        if (form) {
            std::cout << *form << std::endl;
            Bureaucrat bureaucrat("John", 1);
            bureaucrat.signForm(*form);
            bureaucrat.executeForm(*form);
            delete form;
        } else {
            std::cerr << "Failed to create form." << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Intern intern;
        AForm* form;

        form = intern.makeForm("invalid form", "NoTarget");
        if (!form) {
            std::cerr << "Failed to create form with invalid name." << std::endl;
        }
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
