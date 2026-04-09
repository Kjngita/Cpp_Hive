#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	std::cout << "Default constructor for DiamondTrap called\n";
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name) {
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_ep = ScavTrap::getEPScav();
	std::cout << "DiamondTrap " << _name << " is hereee\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) {
	*this = other;
	std::cout << "DiamondTrap copy constructor\n";
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " is goneee\n";
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other)
	{
		_name = other._name;
		ClapTrap::_name = other.ClapTrap::_name;
		_hp = other._hp;
		_ep = other._ep;
		_atkDMG = other._atkDMG;
	}
	std::cout << "DiamondTrap copy assignment operator\n";
	return (*this);
}

void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap's name is " << _name << " and also answers to "
			<< ClapTrap::_name << std::endl;
}