#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	type = "Alien";
	std::cout << "WrongAnimal landed\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	*this = other;
	std::cout << "Copy constructor for WrongAnimal\n";
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal slaughtered\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Copy assignment for WrongAnimal\n";
	return (*this);
}

std::string	WrongAnimal::getType() const { return type; }

void	WrongAnimal::makeSound() const {
	std::cout << "[alien language] &^$&%#^$*%)\n";
}