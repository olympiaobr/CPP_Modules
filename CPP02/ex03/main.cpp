#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    Point a(0.0f, 0.0f);
    Point b(1.0f, 0.0f);
    Point c(0.5f, 1.0f);
    Point inside(0.5f, 0.5f);
    Point outside(1.0f, 1.0f);

    std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;

    return 0;
}
