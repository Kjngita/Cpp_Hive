#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		virtual ~FragTrap();
		FragTrap& operator=(const FragTrap& other);

		void	highFiveGuys(void);
};