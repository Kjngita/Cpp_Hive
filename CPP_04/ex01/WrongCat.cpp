#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "Nyanko";
	std::cout << "WrongCat adopted\n";
}

WrongCat::WrongCat(const WrongCat& other) {
	*this = other;
	std::cout << "Copy constructor for WrongCat\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat ran away\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
	{
		type = other.type;
	}
	std::cout << "Copy assignment for WrongCat\n";
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Nyannn~\n";
}