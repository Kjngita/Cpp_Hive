#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _nameScav("Default Scav"), _hpScav(-1), _epScav(0), _atkDMGScav(0) {
	std::cout << "Default constructor for ScavTrap called\n";
}

ScavTrap::ScavTrap(std::string name) {
	_nameScav = name;
	_hpScav = 100;
	_epScav = 50;
	_atkDMGScav = 20;
	std::cout << "ScavTrap code name " << _nameScav << " reports for duty\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) {
	std::cout << "Copy constructor for ScavTrap was ordered\n";
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _nameScav << " is released of duty\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator was used\n";
	if (this != &other)
	{
		_nameScav = other._nameScav;
		_hpScav = other._hpScav;
		_epScav = other._epScav;
		_atkDMGScav = other._atkDMGScav;
	}
	return *this;
}

void	ScavTrap::setName(std::string newName) {
	std::cout << "* " << _nameScav << " will now be called " << newName << " *\n";
	_nameScav = newName;
}

void	ScavTrap::attack(const std::string& target) {
	if (_hpScav <= 0)
	{
		std::cout << _nameScav << " is too dead to attack :(\n";
		return ;
	}
	if (_epScav == 0)
	{
		std::cout << _nameScav << " is too tired to attack ";
		std::cout << target << " :(\n";
		return ;
	}
	std::cout << "ScavTrap " << _nameScav << " dealt " << _atkDMGScav;
	std::cout << " DMG to " << target  << "!\n";
	_epScav--;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (_hpScav <= 0)
	{
		std::cout << _nameScav << " is too dead to receive ";
		std::cout << amount << " DMG >_<\n";
		return ;
	}
	std::cout << "ScavTrap " << _nameScav << " took a hit of " << amount;
	std::cout << " DMG!\n";
	_hpScav = _hpScav - amount;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (_hpScav <= 0)
	{
		std::cout << _nameScav << " is too dead to repair :(\n";
		return ;
	}
	if (_epScav == 0)
	{
		std::cout << _nameScav << " is too tired to repair :(\n";
		return ;
	}
	std::cout << "ScavTrap " << _nameScav << " repaired itself. ";
	std::cout << amount << " HP gained!\n";
	_epScav--;
}

void	ScavTrap::guardGate() {
	if (_hpScav <= 0)
	{
		std::cout << "Pls revive " << _nameScav << " to guard gate T_T\n";
		return ;
	}
	std::cout << "ScavTrap " << _nameScav << " entered Gate Keeper mode!\n";
}