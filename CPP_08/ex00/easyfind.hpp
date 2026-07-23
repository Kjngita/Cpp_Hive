#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& bucket, int num)
{
	typename T::iterator iter = std::find(bucket.begin(), bucket.end(), num);
	if (iter != bucket.end())
		return iter;
	throw std::out_of_range("Element not found");
}

template <typename T>
typename T::const_iterator easyfind(const T& bucket, int num)
{
	typename T::const_iterator iter = std::find(bucket.begin(), bucket.end(), num);
	if (iter != bucket.end())
		return iter;
	throw std::out_of_range("Element not found");
}