#include "whatever.hpp"
#include <iostream>

int main( void ) {
	std::cout << "[ Int ]\n";
	int a = 23;
	int b = 68;
	std::cout << "Orig: a = " << a << " ; b = " << b << std::endl;
	::swap( a, b );
	std::cout << "Swap: a = " << a << " ; b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << "\n[ String ]\n";
	std::string c = "hihi";
	std::string d = "haha";
	std::cout << "Orig: c = " << c << " ; d = " << d << std::endl;
	::swap(c, d);
	std::cout << "Swap: c = " << c << " ; d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}