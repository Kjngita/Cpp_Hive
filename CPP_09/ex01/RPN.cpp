#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {}

RPN::~RPN() {}

inline std::string_view splitTokens(std::string_view& str)
{
	auto pos = str.find(' ');
	auto splited = str.substr(0, pos);
	str = (pos == std::string_view::npos) ? std::string_view{} : str.substr(pos + 1);
	return splited;
}

inline long long apply_operator(int left, std::string_view& op, int right)
{

}

bool	RPN::calculatable(std::string_view& problem, int& result) {
	std::stack<int>	stk;
	
	while (!problem.empty())
	{
		std::string	token = std::string(splitTokens(problem));
		if (token.length() == 1 && std::isdigit(token[0]))
			stk.push(std::atoi(token.c_str()));
		else if (token.length() == 1 && (token[0] == '+'
			|| token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (stk.size() != 2)
				return false;
			int	right = stk.top();
			stk.pop();
			int left = stk.top();
			stk.pop();
            // long long res = apply_operator(first, token, second)
            // stack.push(res)
		}
		else
			return false;
	}
	if (stk.size() == 1 && stk.top() <= INT_MAX) {
		result = stk.top();
		stk.pop();
		return true;
	}
	return false;
}