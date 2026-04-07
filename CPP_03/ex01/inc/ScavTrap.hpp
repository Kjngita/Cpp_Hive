#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		std::string	_nameScav;
		int			_hpScav;
		int			_epScav;
		int			_atkDMGScav;
		
		public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);
		void			setName(std::string newName);
		virtual void	attack(const std::string& target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		void			guardGate();
};