#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade is too low!";
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {

    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), isSigned(other.isSigned),
      gradeRequiredToSign(other.gradeRequiredToSign), gradeRequiredToExecute(other.gradeRequiredToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeRequiredToSign)
        throw GradeTooLowException();
    isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
        << ", Grade required to sign: " << form.getGradeRequiredToSign()
        << ", Grade required to execute: " << form.getGradeRequiredToExecute();
    return out;
}
