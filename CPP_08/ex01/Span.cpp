#include "Span.hpp"

Span::Span() : _storage() {}

Span::Span(unsigned int N) {
	_storage.reserve(N);
}

Span::Span(const Span& other)
	: _storage(other._storage) {}

Span::~Span() {}

Span& Span::operator=(const Span& other) {
	if (this != &other)
		_storage = other._storage;
	return *this;
}

void	Span::addNumber(int toAdd) {
	if (_storage.size() >= _storage.capacity())
		throw std::out_of_range("No more room to add number");
	_storage.push_back(toAdd);
}

unsigned int	Span::shortestSpan() {
	if (_storage.size() < 2)
		throw std::logic_error("No comparison possible");
	std::vector<int>	organized = _storage;
	std::sort(organized.begin(), organized.end());
	unsigned int shortSpan = organized[1] - organized[0]; //in case array is { INT_MIN, INT_MAX }
	for (size_t	i = 2; i < organized.size(); i++) {
		unsigned int candidate = organized[i] - organized[i-1];
		if (shortSpan > candidate)
			shortSpan = candidate;
	}
	return shortSpan;
}

unsigned int	Span::longestSpan() {
	if (_storage.size() < 2)
		throw std::logic_error("No comparison possible");
	auto minmax = std::minmax_element(_storage.begin(), _storage.end());
	unsigned int	longSpan = *minmax.second - *minmax.first;
	return longSpan;
}