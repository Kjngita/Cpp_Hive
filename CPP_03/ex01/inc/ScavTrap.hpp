#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		virtual ~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);

		virtual void	attack(const std::string& target);
		void			guardGate();
};