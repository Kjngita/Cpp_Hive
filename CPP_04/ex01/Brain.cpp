#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain - default construction\n";
	// _ideas[0] = "Brilliant idea\n";
}

Brain::Brain(const Brain& other) {
	*this = other;
	std::cout << "Brain - copy construction\n";
}

Brain::~Brain() {
	std::cout << "Brain - destructor\n";
}

Brain& Brain::operator=(const Brain& other) {
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = other._ideas[i];
	}
	std::cout << "Brain - copy assignment\n";
	return *this;
}

void	Brain::setIdea(std::string text, int index) {
	if (index < 0 || index > 99)
		return ;
	_ideas[index] = text;
}

std::string	Brain::getIdea(int index) {
	if (index < 0 || index > 99)
		return ("Not within idea range\n");
	return (_ideas[index]);
}