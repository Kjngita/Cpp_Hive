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

void	ClapTrap::showStats() {
	std::cout << _name << ": HP=" << _hp << " EP=" << _ep << " ATK=" << _atkDMG << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hp <= 0)
	{
		std::cout << _name << " is deader than dead to attack :(\n";
		return ;
	}
	if (_ep == 0)
	{
		std::cout << _name << " runs out of battery, cannot attack ";
		std::cout << target << " :(\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << " punches " << target;
	std::cout << " in the face! " << _atkDMG << " DMG dealt!\n";
	_ep--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hp <= 0)
	{
		std::cout << _name << " already dead, still received ";
		std::cout << amount << " DMG >_<\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << " got hit for " << amount;
	std::cout << " DMG, ouch!\n";
	_hp = _hp - amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hp <= 0)
	{
		std::cout << _name << " is deader than dead to repair :(\n";
		return ;
	}
	if (_ep == 0)
	{
		std::cout << _name << " runs out of battery, cannot repair :(\n";
		return ;
	}
	std::cout << "ClapTrap " << _name << " repaired itself for ";
	std::cout << amount << " HP. Bring it on!\n";
	_ep--;
}