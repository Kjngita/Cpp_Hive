#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& thing) : _weapon(thing)
{
	_name = name;
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}