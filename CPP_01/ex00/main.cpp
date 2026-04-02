#include "Zombie.hpp"

int main()
{
	randomChump("Randy");

	Zombie*	pointer = newZombie("Potter");
	pointer->announce();
	delete (pointer);
}
