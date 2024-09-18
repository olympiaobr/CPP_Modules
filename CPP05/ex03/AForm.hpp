#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp" 

class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool signedStatus;
    const int signGrade;
    const int execGrade;

public:
    AForm();
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm& other);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    const std::string& getName() const;
    bool isSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat& bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif

