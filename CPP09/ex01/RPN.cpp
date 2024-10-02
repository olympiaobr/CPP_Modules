#include "RPN.hpp"

RPN::RPN(const std::string &input) : _expression(input)
{
    if (!validateInput(input))
    {
        throw std::invalid_argument("Error: Invalid RPN expression");
    }
}

RPN::RPN(const RPN &other) : _expression(other._expression), _stack(other._stack) {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _expression = other._expression;
        _stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

bool RPN::validateInput(const std::string &input) const
{
    for (size_t i = 0; i < input.size(); ++i)
    {
        if (!isdigit(input[i]) && input[i] != '+' && input[i] != '-' &&
            input[i] != '*' && input[i] != '/' && !isspace(input[i]))
        {
            return false;
        }
    }
    return true;
}

void RPN::calculate()
{
    std::istringstream stream(_expression);
    std::string token;

    while (stream >> token)
    {
        processToken(token);
    }

    if (_stack.size() == 1)
    {
        std::cout << "Result: " << _stack.top() << std::endl;
    }
    else
    {
        std::cerr << "Error: Invalid RPN expression" << std::endl;
    }
}

// Process each token
void RPN::processToken(const std::string &token)
{
    if (isdigit(token[0]))  // If it's a number, push to the stack
    {
        std::stringstream ss(token); // Create stringstream object
        int number;
        ss >> number; // Extract the number from the token

        if (ss.fail()) // Check if the extraction failed (invalid number)
        {
            throw std::invalid_argument("Error: Invalid number in expression");
        }

        _stack.push(number); // Push the valid number to the stack
    }
    else if (token.size() == 1 && (token == "+" || token == "-" || token == "*" || token == "/"))  // Operator
    {
        if (_stack.size() < 2)
        {
            throw std::invalid_argument("Error: Not enough operands");
        }

        int a = _stack.top(); _stack.pop();
        int b = _stack.top(); _stack.pop();

        try
        {
            _stack.push(applyOperator(a, b, token[0]));
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << std::endl;
            throw;
        }
    }
    else
    {
        throw std::invalid_argument("Error: Invalid token in expression");
    }
}


int RPN::applyOperator(const int &a, const int &b, const char &op)
{
    switch (op)
    {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/':
            if (a == 0)
            {
                throw std::invalid_argument("Error: Division by zero");
            }
            return b / a;
        default:
            throw std::invalid_argument("Error: Invalid operator");
    }
}
