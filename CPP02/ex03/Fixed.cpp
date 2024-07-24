#include "Fixed.hpp"
#include <cmath>

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const int value) : fixedPointValue(value << fractionalBits) {}

Fixed::Fixed(const float value) : fixedPointValue(static_cast<int>(roundf(value * (1 << fractionalBits)))) {}

Fixed::Fixed(const Fixed& other) : fixedPointValue(other.fixedPointValue) {}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        fixedPointValue = other.fixedPointValue;
    }
    return *this;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
    return fixedPointValue >> fractionalBits;
}

bool Fixed::operator>(const Fixed& other) const {
    return fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed& other) const {
    return fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed& other) const {
    return fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed& other) const {
    return fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed& other) const {
    return fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed& other) const {
    return fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.fixedPointValue == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        return Fixed();
    }
    return Fixed(toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    ++fixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    --fixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
