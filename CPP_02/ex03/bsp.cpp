#include "Point.hpp"

Fixed	area(const Point& a, const Point& b, const Point& c) {
	Fixed ax = a.getX();
	Fixed ay = a.getY();
	Fixed bx = b.getX();
	Fixed by = b.getY();
	Fixed cx = c.getX();
	Fixed cy = c.getY();

	Fixed res = ax*(by-cy) + bx*(cy-ay) + cx*(ay-by);
	if (res.getRawBits() < 0)
		res = Fixed(0) - res;
	return res;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	area_tri = area(a, b, c);
	Fixed	a1 = area(point, a, b);
	Fixed	a2 = area(point, b, c);
	Fixed	a3 = area(point, a, c);
	std::cout << area_tri << " " << a1 << " " << a2 << " " << a3 << std::endl;
	if (a1.getRawBits() == 0 || a2.getRawBits() == 0 || a3.getRawBits() == 0)
		return (false);
	return (area_tri == a1 + a2 + a3);
}
