#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	// std::cout << "========== OLD TESTS ==========\n\n";

	// ScavTrap	tank("ST-001");

	// // tank.showStats();
	// tank.attack("drone");
	// tank.guardGate();
	// tank.takeDamage(95);
	// tank.beRepaired(5);
	// // tank.showStats();
	// std::cout << std::endl;

	// ScavTrap	knight(tank);
	// // knight.showStats();
	// // knight.setName("ST-002");
	// knight.beRepaired(36);
	// // knight.showStats();
	// std::cout << std::endl;

	// tank.attack("the front line");
	// tank.guardGate();
	// tank.takeDamage(23);
	// // tank.showStats();
	// tank.guardGate();
	// tank.attack("enemy");
	// tank.beRepaired(100);
	// tank.takeDamage(68);
	// std::cout << std::endl;

	// knight.guardGate();
	// std::cout << std::endl;
	// std::cout << "\n========== END OF OLD TESTS ==========\n\n";

	FragTrap	supporter("FT-001");

	supporter.highFiveGuys();
	// supporter.showStats();
	supporter.attack("boss");
	supporter.beRepaired(3216549870);
	// supporter.showStats();
	supporter.takeDamage(2468135790);
	// supporter.showStats();
	supporter.highFiveGuys();

	std::cout << std::endl;
	return 0;
}