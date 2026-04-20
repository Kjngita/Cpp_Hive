#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Nobody"), _grade(150) {
	std::cout << "Default Bureaucrat: " << _name << " - "
			<< _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
	: _name(name), _grade(grade) {
	if (_grade < 1)
		_grade = 1;
	if (_grade > 150)
		_grade = 150;
	std::cout << "Bureaucrat enlisted: " << _name << " - "
			<< _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) :
	_name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copied: " << _name << " - "
			<< _grade << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " got fired\n";
}

// Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
// 	if (this != &other)
// 	{
// 		// _name = other.getName(); //HELPPPPPPPPP
// 		_grade = other._grade;
// 	}
// 	return (*this);
// }

std::string Bureaucrat::getName() const { return _name; }

unsigned int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::upGrade() {
	if (_grade > 1)
		_grade--;
}

void	Bureaucrat::downGrade() {
	if (_grade < 150)
		_grade++;
}