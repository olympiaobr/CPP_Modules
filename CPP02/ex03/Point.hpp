#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
    Fixed const x;
    Fixed const y;

public:
    Point();
    Point(float const x, float const y);
    Point(Point const &other);
    ~Point();

    Fixed getX() const { return x; }
    Fixed getY() const { return y; }
};

#endif

