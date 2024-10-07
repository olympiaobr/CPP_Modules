#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    char *endPtr = NULL;

    long lval = std::strtol(literal.c_str(), &endPtr, 10);
    if (*endPtr == '\0' && lval >= std::numeric_limits<int>::min() && lval <= std::numeric_limits<int>::max()) {
        int i = static_cast<int>(lval);
        std::cout << "char: " << ((i >= 32 && i <= 126) ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return;
    }

    float f = std::strtof(literal.c_str(), &endPtr);
    if (*endPtr == 'f' && *(endPtr + 1) == '\0') {
        if (std::isnan(f) || std::isinf(f)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            int intVal = static_cast<int>(f);
            if (f == intVal && intVal >= 32 && intVal <= 126) {
                std::cout << "char: '" << static_cast<char>(intVal) << "'" << std::endl;
            } else if (f == intVal) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: impossible" << std::endl;
            }
            std::cout << "int: " << intVal << std::endl;
        }
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    double d = std::strtod(literal.c_str(), &endPtr);
    if (*endPtr == '\0') {
        if (std::isnan(d) || std::isinf(d)) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        } else {
            int intVal = static_cast<int>(d);
            if (d == intVal && intVal >= 32 && intVal <= 126) {
                std::cout << "char: '" << static_cast<char>(intVal) << "'" << std::endl;
            } else if (d == intVal) {
                std::cout << "char: Non displayable" << std::endl;
            } else {
                std::cout << "char: impossible" << std::endl;
            }
            std::cout << "int: " << intVal << std::endl;
        }
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    if (literal == "nan" || literal == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    if (literal == "-inf" || literal == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    std::cout << "Error: Invalid literal" << std::endl;
}

