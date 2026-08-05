#pragma once

#include <stack>
#include <iostream>
#include <limits.h>

class RPN
{
	public:
		RPN() = delete;
		~RPN() = delete;
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;

		static int	calculate(std::string& problem);
};