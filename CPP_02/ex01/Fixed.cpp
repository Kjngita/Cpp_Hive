#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor summoned\n";
	_fixedPointNum = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor summoned\n";
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_fixedPointNum = src.getRawBits();
	return (*this);
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called\n";
	_fixedPointNum = num << _bits; //wronggggggggg
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	_fixedPointNum = (int)(roundf(num * (1 << _bits))); //wrongggggg
}

int const Fixed::_bits = 8;

int	Fixed::getRawBits(void) const {
	return (_fixedPointNum);
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointNum = raw;
}

int	Fixed::toInt(void) const {
	return (_fixedPointNum >> _bits);
}

float Fixed::toFloat(void) const {
	return ((float)_fixedPointNum / (float)(1 << _bits));
}

std::ostream& operator<<(std::ostream& output, const Fixed& f) {
	output << f.getRawBits();
	return output;
}