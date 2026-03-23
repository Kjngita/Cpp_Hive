#pragma once

#include <iostream>

class Fixed
{
	private:
		int	_inum;
		static int const _bits;

	public:
		Fixed();
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		int		getRawBits (void) const;
		void	setRawBits(int const raw);
};