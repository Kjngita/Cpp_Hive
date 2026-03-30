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
	int min_int = -(1 << 23);
	int	max_int = (1 << 23) - 1;
	if (num < min_int || num > max_int)
	{
		std::cout << "Integer value out of range to convert to fixed point!\n";
		setRawBits(0);
		return ;
	}
	_fixedPointNum = num << _bits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called\n";
	int min_int = -(1 << 23);
	int	max_int = (1 << 23) - 1;
	if (num < (float)min_int || num > (float)max_int)
	{
		std::cout << "Float value out of range to convert to fixed point!\n";
		setRawBits(0);
		return ;
	}
	_fixedPointNum = (int)(roundf(num * (1 << _bits)));
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
	return ((float)_fixedPointNum / (1 << _bits));
}

std::ostream& operator<<(std::ostream& output, const Fixed& f) {
	output << f.toFloat();
	return output;
}