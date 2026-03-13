#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl	dude;
		dude.complain(av[1]);
	}
	else
		std::cout << "Give one thing for Harl to complain\n";
	return 0;
}