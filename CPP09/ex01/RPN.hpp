#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <exception>
#include <sstream>

class RPN
{
    public:
        // Constructors and Destructor
        RPN(const std::string &input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        // Methods
        void calculate();

    private:
        std::string _expression;
        std::stack<int> _stack;

        // Helper functions
        void processToken(const std::string &token);
        int applyOperator(const int &a, const int &b, const char &op);

        // Input validation
        bool validateInput(const std::string &input) const;
};

#endif // RPN_HPP
