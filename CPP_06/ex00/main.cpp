#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cerr << "[ Usage ]: ./convert <input>\n";
		if (ac < 2)
			std::cerr << "Please provide input for conversion\n";
		else
			std::cerr << "Please provide only one parameter\n";
		return 1;
	}
	ScalarConverter::convert(std::string(av[1]));
	return 0;
}