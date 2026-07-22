#pragma once

#include <iostream>

template <typename T>
typename T::iterator easyfind(T& bucket, int num)
{
	for (typename T::iterator iter = bucket.begin(); iter != bucket.end(); iter++)
		if (*iter == num)
			return iter;
	throw std::out_of_range("Element not found");
}