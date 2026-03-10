#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon	blind_box = Weapon("crude spiked club");
	
		HumanA	bob("Bob", blind_box);
		bob.attack();
		blind_box.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	surprise = Weapon("crude spiked club");
	
		HumanB	jim("Jim");
		jim.attack();
		jim.setWeapon(surprise);
		jim.attack();
		surprise.setType("some other type of club");
		jim.attack();
	}
	return 0;
}