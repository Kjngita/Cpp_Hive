#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *army = new Zombie[N];
	for (int i = 0; i < N; i++) {
		army[i].setName(name);
	}
	return (army);
}