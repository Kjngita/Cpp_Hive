#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	_thoughtsCat = new Brain();
	std::cout << "Cat adopted\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	_thoughtsCat = new Brain(*other._thoughtsCat);
	std::cout << "Copy constructor for Cat\n";
}

Cat::~Cat() {
	delete _thoughtsCat;
	std::cout << "Cat ran away\n";
}

Cat& Cat::operator=(const Cat& other) {
	if (this != &other)
	{
		Animal::operator=(other);
		Brain* tmp = new Brain(*other._thoughtsCat);
		delete _thoughtsCat;
		_thoughtsCat = tmp;
		type = other.type;
	}
	std::cout << "Copy assignment for Cat\n";
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meowww~\n";
}

void	Cat::setThoughts(std::string text, int index) {
	if (index < 0 || index > 99)
		return ;
	_thoughtsCat->setIdea(text, index);
}

std::string Cat::getThoughts(int index) const {
	if (index < 0 || index > 99)
		return ("[ Not within idea range ]\n");
	return _thoughtsCat->getIdea(index);
}