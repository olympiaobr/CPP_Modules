#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), target(other.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream outfile((target + "_shrubbery").c_str());
    if (outfile.is_open()) {
        outfile << "        _\n";
        outfile << "       /_\\\n";
        outfile << "      /___\\\n";
        outfile << "     /_____\\\n";
        outfile << "    /_______\\\n";
        outfile << "   /_________\\\n";
        outfile << "  /___________\\\n";
        outfile << " /_____________\\\n";
        outfile << "      ||\n";
        outfile << "      ||\n";
        outfile << "      ||\n";
        outfile.close();
    } else {
        std::cerr << "Failed to create file" << std::endl;
    }
}


