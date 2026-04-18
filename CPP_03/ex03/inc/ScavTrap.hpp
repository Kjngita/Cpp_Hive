#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	protected:
		static const int	_hpScav = 100;
		static const int	_epScav = 50;
		static const int	_atkScav = 20;
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		virtual ~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);

		virtual void	attack(const std::string& target);
		void			guardGate();
};