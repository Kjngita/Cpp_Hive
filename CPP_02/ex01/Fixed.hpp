#pragma once

#include <iostream>
#include <cmath>

#define	MAX_ALLOWED_INT (1 << 23) - 1
#define MIN_ALLOWED_INT -(1 << 23)

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
};

std::ostream& operator<<(std::ostream& output, const Fixed& f);