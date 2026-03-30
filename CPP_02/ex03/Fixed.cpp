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

Fixed& Fixed::operator+(const Fixed& other) {
	_fixedPointNum = _fixedPointNum + other._fixedPointNum;
	return *this;
}

Fixed& Fixed::operator-(const Fixed& other) {
	_fixedPointNum = _fixedPointNum - other._fixedPointNum;
	return *this;
}

/* Multiply first to preserve fraction, then divide to rescale*/
Fixed& Fixed::operator*(const Fixed& other) {
	_fixedPointNum = (_fixedPointNum * other._fixedPointNum) >> _bits;
	return *this;
}

/* Multiply by scale first to preserve fraction (<< _bits = * _bits), then divide*/
Fixed& Fixed::operator/(const Fixed& other) {
	_fixedPointNum = (_fixedPointNum << _bits) / other._fixedPointNum;
	return *this;
}

Fixed& Fixed::operator++() {
	_fixedPointNum++;
	return (*this);
}

Fixed& Fixed::operator--() {
	_fixedPointNum--;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed	temp = *this;
	_fixedPointNum++;
	return (temp);
}

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