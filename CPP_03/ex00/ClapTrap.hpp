#pragma once

#include <iostream>

class ClapTrap
{
	private:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_atkDMG;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};