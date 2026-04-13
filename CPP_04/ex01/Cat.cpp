#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	_thoughtsCat = new Brain();
	std::cout << "Cat adopted\n";
}

Cat::Cat(const Cat& other) {
	*this = other;
	std::cout << "Copy constructor for Cat\n";
}

Cat::~Cat() {
	delete _thoughtsCat;
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

void	Cat::setThoughts() {
	_thoughtsCat->setIdea("Whatever\n", 0);
}

std::string Cat::getThoughts() const {
	return _thoughtsCat->getIdea(0);
}