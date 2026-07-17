#pragma once
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _size(0), _arr(nullptr) {}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array& other)
	: _size(other._size), _arr(new T[other._size]()) {
	for (unsigned int i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
}

template <typename T>
Array<T>::~Array() {
	delete[] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other)
	{
		delete[] _arr;
		_size = other._size;
		_arr = new T[_size]();
		for (unsigned int i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <typename T>
Array<T>& Array<T>::operator[](unsigned int index) {
	if (index < _size)
		return _arr[index];
	throw std::out_of_range("Index out of bound");
}

template <typename T>
unsigned int Array<T>::size() const { return _size; }

