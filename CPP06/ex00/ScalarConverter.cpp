#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>

// Helper functions to identify the type of the literal
bool isCharLiteral(const std::string &literal) {
    return literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0]);
}

bool isIntLiteral(const std::string &literal) {
    char *end;
    long value = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && errno != ERANGE && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max();
}

bool isFloatLiteral(const std::string &literal) {
    char *end;
    std::strtof(literal.c_str(), &end);
    return *end == 'f' && *(end + 1) == '\0';
}

bool isDoubleLiteral(const std::string &literal) {
    char *end;
    std::strtod(literal.c_str(), &end);
    return *end == '\0';
}

// Conversion method
void ScalarConverter::convert(const std::string &literal) {
    // Handle char literal
    if (isCharLiteral(literal)) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // Handle int literal
    if (isIntLiteral(literal)) {
        int i = std::atoi(literal.c_str());
        std::cout << "char: " << ((i >= 32 && i <= 126) ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
        return;
    }

    // Handle float literal
    if (isFloatLiteral(literal)) {
        float f = std::strtof(literal.c_str(), NULL);
        if (std::isnan(f) || std::isinf(f) || f < 32 || f > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
        return;
    }

    // Handle double literal
    if (isDoubleLiteral(literal)) {
        double d = std::strtod(literal.c_str(), NULL);
        if (std::isnan(d) || std::isinf(d) || d < 32 || d > 126) {
            std::cout << "char: Non displayable" << std::endl;
        } else {
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        }
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    // Handle pseudoliterals (nan, +inf, -inf)
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

    // If no match, output error
    std::cout << "Error: Invalid literal" << std::endl;
}


