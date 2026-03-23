#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor summoned\n";
	_inum = 0;
}

Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_inum = src.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor summoned\n";
}

int const Fixed::_bits = 8;

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (_inum);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	_inum = raw;
}