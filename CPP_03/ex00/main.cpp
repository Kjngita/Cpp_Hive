#include "ClapTrap.hpp"

int main()
{
ClapTrap	pet("CT-01");
	
	pet.attack("Terminator");
	pet.takeDamage(7);
	pet.beRepaired(2);
	pet.beRepaired(0);
	pet.beRepaired(0);
	pet.beRepaired(0);
	pet.beRepaired(0);
	pet.beRepaired(0);
	pet.beRepaired(0);
	pet.beRepaired(0);
	pet.beRepaired(1);
	// pet.showStats();

	std::cout << std::endl;

	ClapTrap	pet2 = pet;
	// pet2.setName("CT-02");
	// pet2.showStats();
	pet2.attack("AI");

	std::cout << std::endl;
	
	pet.attack("Terminator");
	pet.takeDamage(12);
	pet.takeDamage(5);
	pet.beRepaired(2);
	pet.attack("Terminator");
	// pet.showStats();

	std::cout << std::endl;
	
	pet2.attack("AI");
	// pet2.showStats();
	
	std::cout << std::endl;
	return 0;
}