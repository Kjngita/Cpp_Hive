#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "Default constructor for FragTrap called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hp = 100;
	_ep = 100;
	_atkDMG = 30;
	std::cout << "FragTrap named " << _name << " is ready for action\n";
}

FragTrap::FragTrap(const FragTrap& other) {
	*this = other;
	std::cout << "FragTrap copy constructor happened\n";
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " is done for today\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
	{
		_name = other._name;
		_hp = other._hp;
		_ep = other._ep;
		_atkDMG = other._atkDMG;
	}
	std::cout << "FragTrap copy assignment operator happened\n";
	return (*this);
}

void	FragTrap::highFiveGuys(void) {
	if (_hp == 0)
	{
		std::cout << "Would be nice if FragTrap " << _name
				<< " was still alive to high five T_T\n";
		return ;
	}
	std::cout << "FragTrap " << _name 
			<< " said: Hit me baby one more time, my palm up here :3\n";
}