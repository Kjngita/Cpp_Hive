#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hp(0), _ep(0), _atkDMG(0) {
	std::cout << "Default constructor for ClapTrap called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atkDMG(0){
	std::cout << "A new ClapTrap appeared. Code name: ";
	std::cout << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor was ordered\n";
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "Salute! ClapTrap " << _name << " was destroyed\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Proceed with copy assignment operator\n";
	if (this != &other)
	{
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_atkDMG = other._atkDMG;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (_hp == 0)
	{
		std::cout << "_clap " << _name << " is deader than dead to attack :(\n";
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "_clap " << _name << " runs out of battery, cannot attack "
				<< target << " :(\n";
		return ;
	}
	std::cout << "_clap " << _name << " punches " << target
			<< " in the face! " << _atkDMG << " DMG dealt!\n";
	_ep--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hp == 0)
	{
		std::cout << "_clap " << _name << " already dead, still received "
				<< amount << " DMG >_<\n";
		return ;
	}
	std::cout << "_clap " << _name << " got hit for " << amount
			<< " DMG, ouch!\n";
	if (amount > 2147483647)
		amount = 2147483647;
	_hp = _hp - amount;
	if (_hp < 0)
		_hp = 0;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hp == 0)
	{
		std::cout << "_clap " << _name << " is deader than dead to repair :(\n";
		return ;
	}
	if (_ep == 0)
	{
		std::cout << "_clap " << _name << " runs out of battery, cannot repair :(\n";
		return ;
	}
	if (amount > 2147483647 || _hp + amount > 2147483647)
		amount = 2147483647 - _hp;
	std::cout << "_clap " << _name << " repaired itself for "
			<< amount << " HP. Bring it on!\n";
	_hp = _hp + amount;
	_ep--;
}

void	ClapTrap::setName(std::string newName) {
	std::cout << "** This " << _name << " will now identify as " << newName << " **\n";
	_name = newName;
}

void	ClapTrap::showStats() {
	std::cout << "// [" << _name << "]: HP=" << _hp << " EP=" << _ep << " ATK=" << _atkDMG << " //\n";
}