#include "Weapon.hpp"
#include "HumanA.hpp"

int main()
{
	Weapon	club = Weapon("crude spiked club");

	HumanA	bob("Bob", club);
	bob.attack();
	std::cout << club.getType() << " -> ";
	club.setType("some other club");
	std::cout << club.getType() << std::endl;
	bob.attack();
}