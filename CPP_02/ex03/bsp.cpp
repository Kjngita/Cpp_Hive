#include "Point.hpp"

Fixed	area(const Point& a, const Point& b, const Point& c) {
	Fixed ax = a.getX();
	Fixed ay = a.getY();
	Fixed bx = b.getX();
	Fixed by = b.getY();
	Fixed cx = c.getX();
	Fixed cy = c.getY();

	Fixed res = ax*(by-cy) + bx*(cy-ay) + cx*(ay-by);
	if (res < Fixed(0))
		res = Fixed(0) - res;
	return (res / 2);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area_tri = area(a, b, c);
	Fixed	a1 = area(point, a, b);
	Fixed	a2 = area(point, b, c);
	Fixed	a3 = area(point, a, c);
	if (a1.getRawBits() == 0 || a2.getRawBits() == 0 || a3.getRawBits() == 0)
		return (false);
	Fixed	diff = area_tri - (a1 + a2 + a3);
	if (diff >= 0 && diff < 0.01f)
		return (true);
	else
		return false;
}
