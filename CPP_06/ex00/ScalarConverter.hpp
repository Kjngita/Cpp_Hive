#pragma once

#include <iostream>
#include <cmath>
#include <climits>
#include <cfloat>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;

		static void convert (const std::string& input);
};