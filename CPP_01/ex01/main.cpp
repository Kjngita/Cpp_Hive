#include "Zombie.hpp"

Zombie* newZombie(std::string name);

int main()
{
	Zombie*	clones = zombieHorde(5, "Hodor");
	for (int i = 0; i < 5; i++)
		clones[i].announce();
	delete [] clones;
}
