#pragma once

#include <stack>
#include <iostream>
#include <limits.h>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN& other) = delete;
		RPN& operator=(const RPN& other) = delete;

		bool	calculatable(std::string_view& problem, int& result);
};