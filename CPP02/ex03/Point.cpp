#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const xVal, float const yVal) : x(xVal), y(yVal) {}

Point::Point(Point const &other) : x(other.x), y(other.y) {}

Point::~Point() {}
