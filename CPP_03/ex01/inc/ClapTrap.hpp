#pragma once

#include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_atkDMG;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		virtual ~ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);

		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		// void			setName(std::string newName);
		// void			showStats();
};