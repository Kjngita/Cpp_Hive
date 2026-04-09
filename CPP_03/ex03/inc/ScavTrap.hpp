#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	private:
		static const int	_hpScav;
		static const int	_epScav;
		static const int	_atkScav;
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		virtual ~ScavTrap();
		ScavTrap& operator=(const ScavTrap& other);

		virtual void	attack(const std::string& target);
		void			guardGate();
		int				getEPScav();
};