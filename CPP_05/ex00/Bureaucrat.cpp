#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Nobody"), _grade(150) {
	std::cout << "Default Bureaucrat: " << _name << " - "
			<< _grade << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
	: _name(name), _grade(grade) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
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

std::string Bureaucrat::getName() const { return _name; }

unsigned int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::upGrade() {
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::downGrade() {
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream&	operator<<(std::ostream& output, const Bureaucrat& target) {
	std::cout << target.getName() << ", bureaucrat grade "
			<< target.getGrade();
	return output;
}