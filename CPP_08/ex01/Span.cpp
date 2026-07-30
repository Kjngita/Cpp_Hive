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
		throw std::out_of_range("No more room in here");
	_storage.push_back(toAdd);
}

int		Span::shortestSpan() {
	if (_storage.size() < 2)
		throw std::logic_error("No comparison possible");
	return 0;
}

int		Span::longestSpan() {
	if (_storage.size() < 2)
		throw std::logic_error("No comparison possible");
	return 0;
}