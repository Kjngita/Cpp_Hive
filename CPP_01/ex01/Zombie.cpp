#include "Zombie.hpp"

Zombie::Zombie() {}


Zombie::~Zombie() {
	std::cout << "RIP " << _name << std::endl;
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}
