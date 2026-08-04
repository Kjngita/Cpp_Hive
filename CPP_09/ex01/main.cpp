#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Pls provide one math expression\n";
		return 1;
	}
	std::string problem(av[1]);
	int			res;
	
}