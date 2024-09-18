#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat highGradeBureaucrat("Kiki", 1);
        Bureaucrat lowGradeBureaucrat("Miki", 150);

        // Create forms
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("TargetA");
        PresidentialPardonForm pardon("TargetB");

        // initial states
        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        // Try signing forms
        highGradeBureaucrat.signForm(shrubbery);
        lowGradeBureaucrat.signForm(robotomy);
        highGradeBureaucrat.signForm(pardon);

        // Execute forms
        highGradeBureaucrat.executeForm(shrubbery);
        highGradeBureaucrat.executeForm(robotomy);
        highGradeBureaucrat.executeForm(pardon);

        // Attempt to execute with a bureaucrat who doesn't have the required grade
        lowGradeBureaucrat.executeForm(shrubbery);
        lowGradeBureaucrat.executeForm(robotomy);
        lowGradeBureaucrat.executeForm(pardon);

        // Un-sign and try to execute again
        shrubbery.beSigned(lowGradeBureaucrat);
        robotomy.beSigned(lowGradeBureaucrat);
        pardon.beSigned(lowGradeBureaucrat);

        lowGradeBureaucrat.executeForm(shrubbery);
        lowGradeBureaucrat.executeForm(robotomy);
        lowGradeBureaucrat.executeForm(pardon);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

