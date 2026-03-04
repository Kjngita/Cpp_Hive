#include "Zombie.hpp"

Zombie* newZombie(std::string name);

int main()
{
	randomChump("Randy");

	Zombie*	pointer = newZombie("Potter");
	pointer->announce();
	delete (pointer);
}