#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Unnamed"), signedStatus(false), signGrade(150), execGrade(150) {}

AForm::AForm(const std::string& name, int signGrade, int execGrade)
    : name(name), signedStatus(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name), signedStatus(other.signedStatus),
      signGrade(other.signGrade), execGrade(other.execGrade) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        signedStatus = other.signedStatus;
    }
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::isSigned() const {
    return signedStatus;
}

int AForm::getSignGrade() const {
    return signGrade;
}

int AForm::getExecGrade() const {
    return execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    signedStatus = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << form.getName() << ", sign grade " << form.getSignGrade() << ", exec grade " << form.getExecGrade() << ".";
    return out;
}
