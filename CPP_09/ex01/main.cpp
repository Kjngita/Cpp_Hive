#include "RPN.hpp"

int main(int ac, char **av)
{
	try
	{
		if (ac != 2)
		{
			std::cout << "Pls provide one math expression\n";
			return 1;
		}
		std::string problem(av[1]);
		std::cout << RPN::calculate(problem) << std::endl;
		return 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

// [ Edge cases ]
// Overflow:	"9 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
// Underflow:	"8 9 - 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 * 9 *"
// Divide by 0:	"68 0 /"