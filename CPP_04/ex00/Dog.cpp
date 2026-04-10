#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "Dog adopted\n";
}

Dog::Dog(const Dog& other) {
	*this = other;
	std::cout << "Copy constructor for Dog\n";
}

Dog::~Dog() {
	std::cout << "Dog ran away\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Copy assignment for Dog\n";
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << "Woof woof\n";
}