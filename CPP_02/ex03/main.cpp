#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point A(0, -5.6);
	Point B(20.63, 4.76);
	Point C(0, 23.9);
	Point P(0, 7.83);

	if (bsp(A, B, C, P))
		std::cout << "True!\n";
	else
		std::cout << "False!\n";
	return 0;
}

/*
https://www.desmos.com/calculator/bi14xz1jci
For visualizing triangle. Add following equation to finish the triangle:
y - y3 = s3(x - x3){x1 < x < x3}
*/