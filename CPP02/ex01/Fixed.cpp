#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& assign)
{
    if (this != &assign)
	{
        fixedPointValue = assign.fixedPointValue;
    }
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(fixedPointValue) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{

    return fixedPointValue >> fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return out;
}

