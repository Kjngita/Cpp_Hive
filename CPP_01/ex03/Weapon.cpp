#include "Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(std::string weapon)
{
	_type = weapon;
}

Weapon::~Weapon() {}

void	Weapon::setType(std::string new_type)
{
	_type = new_type;
}

std::string	Weapon::getType()
{
	return (_type);
}