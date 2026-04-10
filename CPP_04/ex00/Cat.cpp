#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "Cat adopted\n";
}

Cat::Cat(const Cat& other) {
	*this = other;
	std::cout << "Copy constructor for Cat\n";
}

Cat::~Cat() {
	std::cout << "Cat ran away\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Copy assignment for Cat\n";
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meowww~\n";
}