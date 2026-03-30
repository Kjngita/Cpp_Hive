#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed	x;
		Fixed	y;

	public:
		Point();
		~Point();
		Point(const float x, const float y);
		Point(const Point& src);
		Point& operator=(const Point& other);
		Fixed	getX() const;
		Fixed	getY() const;
};

Fixed	area(const Point& a, const Point& b, const Point& c);
bool	bsp( Point const a, Point const b, Point const c, Point const point);