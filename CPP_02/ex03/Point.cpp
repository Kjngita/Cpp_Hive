#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point::Point(const float param_x, const float param_y) : x(param_x), y(param_y) {}

Point::Point(const Point& src) {
	*this = src;
}

Point& Point::operator=(const Point& other) {
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

Fixed	Point::getX() const {
	return (x);
}

Fixed	Point::getY() const {
	return (y);
}