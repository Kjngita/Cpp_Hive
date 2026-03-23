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
	_fixedPointNum = num << _bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	_fixedPointNum = num; //wrongggg
}

int const Fixed::_bits = 8;

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_fixedPointNum);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_fixedPointNum = raw;
}

int	Fixed::toInt(void) const {
	return (_fixedPointNum >> _bits);
}

float Fixed::toFloat(void) const {
	return (_fixedPointNum * (1 << _bits)); //wrongggggggg
}