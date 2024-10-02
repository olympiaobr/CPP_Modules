#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments is provided
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN <expression>" << std::endl;
        return 1;
    }

    try
    {
        // Create an RPN object with the user input
        RPN rpn(argv[1]);

        // Perform the calculation
        rpn.calculate();
    }
    catch (const std::exception &e)
    {
        // Catch any exceptions and print the error message
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
