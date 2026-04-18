#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	bling("Carbon");

	std::cout << std::endl;
	bling.whoAmI();
	std::cout << std::endl;

	bling.showStats();
	bling.attack("jewel thief");
	bling.beRepaired(3000000000);
	bling.showStats();
	bling.guardGate();
	bling.highFiveGuys();
	bling.takeDamage(3000000000);
	bling.showStats();
	bling.attack("jewel thief");

	std::cout << std::endl;
	return 0;
}