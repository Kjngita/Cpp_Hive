#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon_ptr = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon& ref)
{
	_weapon_ptr = &ref;
}

void	HumanB::attack()
{
	if (!_weapon_ptr)
		std::cout << _name << " doesn't have a weapon\n";
	else
		std::cout << _name << " attacks with their " << _weapon_ptr->getType() << std::endl;
}