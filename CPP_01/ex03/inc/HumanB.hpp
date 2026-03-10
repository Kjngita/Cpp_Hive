#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon*		_weapon_ptr;

	public:
		HumanB(std::string name);
		~HumanB();
		void	setWeapon(Weapon& thing);
		void	attack();
};