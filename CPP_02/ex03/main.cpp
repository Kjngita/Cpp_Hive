#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point A(0, 0);
	Point B(20, 0);
	Point C(0, 30);
	Point P(1, 1);

	if (bsp(A, B, C, P))
		std::cout << "True!\n";
	else
		std::cout << "False!\n";
	return 0;
}