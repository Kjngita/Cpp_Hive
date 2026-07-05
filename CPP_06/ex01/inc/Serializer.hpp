#pragma once

#include <cstdint>
#include "Data.hpp"

class Serializer
{
	public:
		Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		~Serializer() = delete;
		Serializer& operator=(const Serializer& other) = delete;

		static uintptr_t serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};