#pragma once
#include <iostream>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T*				_arr;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		~Array();
		Array& operator=(const Array& other);
		T& operator[](unsigned int index);
		T& operator[](unsigned int index) const;

		unsigned int size() const;
};

#include "Array.tpp"