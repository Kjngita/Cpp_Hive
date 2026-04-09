#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "Default constructor for ScavTrap called\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hp = 100;
	_ep = 50;
	_atkDMG = 20;
	std::cout << "ScavTrap code name " << _name << " reports for duty\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	*this = other;
	std::cout << "ScavTrap copy constructor was ordered\n";
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " is released of duty\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other)
	{
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_atkDMG = other._atkDMG;
	}
	std::cout << "ScavTrap copy assignment operator was used\n";
	return (*this);
}

void	ScavTrap::attack(const std::string& target) {
	if (_hp == 0)
	{
		std::cout << "_scav " << _name << " is way too dead to attack :(\n";
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "_scav " << _name << " is way too tired to attack "
				<< target << " :(\n";
		return ;
	}
	std::cout << "_scav " << _name << " dealt " << _atkDMG
			<< " DMG to " << target  << "!\n";
	_ep--;
}

void	ScavTrap::guardGate() {
	if (_hp == 0)
	{
		std::cout << "Pls revive ScavTrap " << _name << " to guard gate T_T\n";
		return ;
	}
	std::cout << "ScavTrap " << _name << " entered Gate Keeper mode!\n";
}