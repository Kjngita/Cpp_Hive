#pragma once

#include <iostream>
#include <cmath>
#include <climits>

class ScalarConverter
{
	public:
		ScalarConverter() = delete;
		~ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		ScalarConverter& operator=(const ScalarConverter& other) = delete;

		static void convert (const std::string& input);
};