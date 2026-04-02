#include "Fixed.hpp"

Fixed::Fixed() {
	_fixedPointNum = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed& src) {
	*this = src;
}

Fixed& Fixed::operator=(const Fixed& src) {
	if (this != &src)
		this->_fixedPointNum = src.getRawBits();
	return (*this);
}

Fixed::Fixed(const int num) {
	if (num < MIN_ALLOWED_INT || num > MAX_ALLOWED_INT)
	{
		std::cout << "Integer value out of range to convert to fixed point!\n";
		setRawBits(0);
		return ;
	}
	_fixedPointNum = num << _bits;
}

Fixed::Fixed(const float num) {
	if (num < (float)MIN_ALLOWED_INT || num > (float)MAX_ALLOWED_INT)
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

bool Fixed::operator>(const Fixed& other) {
	return (_fixedPointNum > other._fixedPointNum);
}

bool Fixed::operator<(const Fixed& other) {
	return (_fixedPointNum < other._fixedPointNum);
}

bool Fixed::operator>=(const Fixed& other) {
	return (_fixedPointNum >= other._fixedPointNum);
}

bool Fixed::operator<=(const Fixed& other) {
	return (_fixedPointNum <= other._fixedPointNum);
}

bool Fixed::operator==(const Fixed& other) {
	return (_fixedPointNum == other._fixedPointNum);
}

bool Fixed::operator!=(const Fixed& other) {
	return (_fixedPointNum != other._fixedPointNum);
}

/*
For arithmatics operators, return a new value instead of modifying original object.
*/

Fixed Fixed::operator+(const Fixed& other) {
	Fixed	res;
	res._fixedPointNum = _fixedPointNum + other._fixedPointNum;
	return res;
}

Fixed Fixed::operator-(const Fixed& other) {
	Fixed	res;
	res._fixedPointNum = _fixedPointNum - other._fixedPointNum;
	return res;
}

//Multiply first to preserve fraction, then divide to rescale
Fixed Fixed::operator*(const Fixed& other) {
	Fixed	res;
	res._fixedPointNum = (_fixedPointNum * other._fixedPointNum) >> _bits;
	return res;
}

//Multiply by scale first to preserve fraction (<< _bits = * _bits), then divide
Fixed Fixed::operator/(const Fixed& other) {
	Fixed	res;
	res._fixedPointNum = (_fixedPointNum << _bits) / other._fixedPointNum;
	return res;
}

//Pre-increment
Fixed& Fixed::operator++() {
	_fixedPointNum++;
	return (*this);
}

//Pre-decrement
Fixed& Fixed::operator--() {
	_fixedPointNum--;
	return (*this);
}

//Post-increment
Fixed Fixed::operator++(int) {
	Fixed	temp = *this;
	_fixedPointNum++;
	return (temp);
}

//Post-decrement
Fixed Fixed::operator--(int) {
	Fixed	temp = *this;
	_fixedPointNum--;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if (a._fixedPointNum < b._fixedPointNum)
		return (a);
	return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if (a._fixedPointNum > b._fixedPointNum)
		return (a);
	return (b);
}