#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	private:
		static const int	_hpFrag = 100;
		static const int	_epFrag = 100;
		static const int	_atkFrag = 30;

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		virtual ~FragTrap();
		FragTrap& operator=(const FragTrap& other);

		void	highFiveGuys(void);
		int		getHPFrag();
		int		getATKFrag();
};