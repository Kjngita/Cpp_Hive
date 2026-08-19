#include "RPN.hpp"

inline std::string splitTokens(std::string& str)
{
	size_t pos = str.find(' ');
	std::string tok = str.substr(0, pos);
	str = (pos == std::string::npos) ? std::string{} : str.substr(pos + 1);
	return tok;
}

inline int apply_operator(int left, std::string& op, int right)
{
	long res;
	if (op == "+")
		res = static_cast<long>(left) + right;
	else if (op == "-")
		res = static_cast<long>(left) - right;
	else if (op == "*")
		res = static_cast<long>(left) * right;
	else
	{
		if (right == 0)
			throw std::logic_error("Cannot divide by 0");
		res = static_cast<long>(left) / right;
	}
	if (res < INT_MIN || res > INT_MAX)
		throw std::overflow_error("Integer over/underflow");
	return res;
}

int	RPN::calculate(std::string& problem) {
	std::stack<int>	stk;
	
	while (!problem.empty())
	{
		std::string	token = std::string(splitTokens(problem));
		if (token.empty())
			continue;
		if (token.length() == 1 && std::isdigit(token[0]))
			stk.push(std::atoi(token.c_str()));
		else if (token.length() == 1 && (token[0] == '+'
			|| token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (stk.size() < 2)
				throw std::logic_error("Not enough param for calculation");
			int	right = stk.top();
			stk.pop();
			int left = stk.top();
			stk.pop();
            int res = apply_operator(left, token, right);
            stk.push(res);
		}
		else
			throw std::invalid_argument("Error");
	}
	if (stk.size() != 1)
		throw std::logic_error("Missing operator");
	return stk.top();
}
