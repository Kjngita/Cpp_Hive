#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	// std::cout << "========== OLD TESTS ==========\n\n";
	// ClapTrap	pet("CT-001");
	
	// pet.attack("Terminator");
	// pet.takeDamage(7);
	// pet.beRepaired(2);
	// pet.beRepaired(0);
	// pet.beRepaired(0);
	// pet.beRepaired(0);
	// pet.beRepaired(0);
	// pet.beRepaired(0);
	// pet.beRepaired(0);
	// pet.beRepaired(0);
	// pet.beRepaired(1);
	// // pet.showStats();

	// std::cout << std::endl;

	// ClapTrap	pet2 = pet;
	// // pet2.setName("CT-02");
	// // pet2.showStats();
	// pet2.attack("AI");

	// std::cout << std::endl;
	
	// pet.attack("Terminator");
	// pet.takeDamage(12);
	// pet.takeDamage(5);
	// pet.beRepaired(2);
	// pet.attack("Terminator");
	// // pet.showStats();

	// std::cout << std::endl;
	
	// pet2.attack("AI");
	// // pet2.showStats();
	
	// std::cout << "\n========== END OF OLD TESTS ==========\n\n";
	
	ScavTrap	tank("ST-001");

	// tank.showStats();
	tank.attack("drone");
	tank.guardGate();
	tank.takeDamage(95);
	tank.beRepaired(5);
	// tank.showStats();
	std::cout << std::endl;

	ScavTrap	knight(tank);
	// knight.showStats();
	// knight.setName("ST-002");
	knight.beRepaired(36);
	// knight.showStats();
	std::cout << std::endl;

	tank.attack("the front line");
	tank.guardGate();
	tank.takeDamage(23);
	// tank.showStats();
	tank.guardGate();
	tank.attack("enemy");
	tank.beRepaired(100);
	tank.takeDamage(68);
	std::cout << std::endl;

	knight.guardGate();
	std::cout << std::endl;
	
	return 0;
}