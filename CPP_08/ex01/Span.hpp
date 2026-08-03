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

		void			addNumber(int toAdd);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		template <typename InputIter>
		void	massFill(InputIter start, InputIter stop)
		{
			// if (_storage.size() + std::distance(start, stop) > _storage.capacity())
			// 	throw std::out_of_range("Not enough room in here");
			// _storage.insert(_storage.end(), start, stop);
			while (start != stop) {
				if (_storage.size() == _storage.capacity())
					throw std::out_of_range("Not enough room in here");
				_storage.push_back(*start);
				start++;
			}
		}


		std::vector<int>&	getArr() { return _storage; }
};