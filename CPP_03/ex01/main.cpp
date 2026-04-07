#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	std::cout << "========== OLD TESTS ==========\n\n";
	ClapTrap	pet("CT-001");
	
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
	pet.showStats();
	std::cout << std::endl;

	ClapTrap	pet2 = pet;
	pet2.attack("AI");
	pet2.showStats();
	
	std::cout << std::endl;
	pet.attack("Terminator");
	pet.takeDamage(12);
	pet.takeDamage(5);
	pet.beRepaired(2);
	pet.attack("Terminator");
	pet.showStats();

	std::cout << std::endl;
	
	pet2.attack("AI");
	pet2.showStats();
	
	std::cout << "\n========== END OF OLD TESTS ==========\n\n";
	
	ScavTrap	tank("ST-001");

	tank.showStats(); //can use ClapTrap public function
	tank.guardGate();
	tank.takeDamage(95);
	tank.beRepaired(5);
	std::cout << std::endl;

	ScavTrap	knight(tank);
	knight.beRepaired(36);
	knight.setName("ST-002");
	std::cout << std::endl;

	tank.attack("the front line");
	tank.guardGate();
	tank.takeDamage(23);
	tank.guardGate();
	tank.attack("enemy");
	tank.beRepaired(100);
	tank.takeDamage(68);
	std::cout << std::endl;

	knight.guardGate();
	
	return 0;
}