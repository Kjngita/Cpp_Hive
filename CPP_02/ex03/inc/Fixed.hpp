#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	_fixedPointNum;
		static int const _bits;

	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& other);
		Fixed(const int num);
		Fixed(const float num);
		int		getRawBits (void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		bool operator>(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);
		Fixed&	operator+(const Fixed& other);
		Fixed&	operator-(const Fixed& other);
		Fixed&	operator*(const Fixed& other);
		Fixed&	operator/(const Fixed& other);
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& output, const Fixed& f);