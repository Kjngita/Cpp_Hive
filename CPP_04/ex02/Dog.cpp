#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	_thoughtsDog = new Brain();
	std::cout << "Dog adopted\n";
}

Dog::Dog(const Dog& other): Animal(other) {
	_thoughtsDog = new Brain(*other._thoughtsDog);
	std::cout << "Copy constructor for Dog\n";
}

Dog::~Dog() {
	delete _thoughtsDog;
	std::cout << "Dog ran away\n";
}

Dog& Dog::operator=(const Dog& other) {
	if (this != &other)
	{
		Animal::operator=(other);
		delete _thoughtsDog;
		_thoughtsDog = new Brain(*(other._thoughtsDog));
	}
	std::cout << "Copy assignment for Dog\n";
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << "Woof woof\n";
}
void	Dog::setThoughts(std::string text, int index) {
	if (index < 0 || index > 99)
		return ;
	_thoughtsDog->setIdea(text, index);
}

std::string Dog::getThoughts(int index) const {
	if (index < 0 || index > 99)
		return ("[ Not within idea range ]\n");
	return _thoughtsDog->getIdea(index);
}