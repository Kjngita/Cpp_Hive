#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		std::vector<int>	_storage;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		~Span();
		Span& operator=(const Span& other);

		void	addNumber(int toAdd);
		int		shortestSpan();
		int		longestSpan();

		template <typename InputIter>
		void	massFill(InputIter start, InputIter stop)
		{
			
		}


		std::vector<int>&	getArr() { return _storage; }
};