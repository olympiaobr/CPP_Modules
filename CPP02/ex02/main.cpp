#include <iostream>
#include "Fixed.hpp"

int main()
{
    Fixed	a;
    Fixed	const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}

/*
int main()
{
    Fixed a;
    std::cout << "Default constructed value (a): " << a << std::endl;

    Fixed b(5.05f);
    Fixed c = b * Fixed(2);
    std::cout << "Float constructed and multiplied value (b * 2): " << c << std::endl;

    std::cout << "a > c: " << (a > c) << std::endl;
    std::cout << "a < c: " << (a < c) << std::endl;
    std::cout << "b >= b: " << (b >= b) << std::endl;
    std::cout << "c <= a: " << (c <= a) << std::endl;
    std::cout << "b == Fixed(5.05f): " << (b == Fixed(5.05f)) << std::endl;
    std::cout << "c != b: " << (c != b) << std::endl;

    Fixed sum = b + c;
    Fixed difference = c - b;
    Fixed product = b * c;
    Fixed quotient = c / Fixed(2.0f);
    std::cout << "Sum (b + c): " << sum << std::endl;
    std::cout << "Difference (c - b): " << difference << std::endl;
    std::cout << "Product (b * c): " << product << std::endl;
    std::cout << "Quotient (c / 2): " << quotient << std::endl;

    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "Current value of a: " << a << std::endl;

    std::cout << "Min of a and b: " << Fixed::min(a, b) << std::endl;
    std::cout << "Max of b and c: " << Fixed::max(b, c) << std::endl;

    return 0;
}
*/
