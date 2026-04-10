#include "Animal.hpp"

Animal::Animal() {
	type = "Alien";
	std::cout << "Animal born\n";
}

Animal::Animal(const Animal& other) {
	*this = other;
	std::cout << "Copy constructor for Animal\n";
}

Animal::~Animal() {
	std::cout << "Animal slaughtered\n";
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Copy assignment for Animal\n";
	return (*this);
}

std::string	Animal::getType() const { return type; }

void	Animal::makeSound() const {
	std::cout << "[alien language] &^$&%#^$*%)\n";
}