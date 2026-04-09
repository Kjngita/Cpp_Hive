#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	bling("Carbon");

	std::cout << std::endl;
	bling.whoAmI();
	std::cout << std::endl;

	bling.showStats();
	bling.attack("jewellry thief");
	bling.guardGate();
	bling.highFiveGuys();

	std::cout << std::endl;
	return 0;
}