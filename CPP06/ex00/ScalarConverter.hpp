#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>   // for std::atoi, std::strtof, std::strtod
#include <limits>    // for checking limits (infinity, etc.)
#include <cmath>     // for std::isnan, std::isinf

class ScalarConverter {
private:
    // Private constructor to prevent instantiation
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();

public:
    // Static method to convert a scalar type from string input
    static void convert(const std::string &literal);
};

#endif
