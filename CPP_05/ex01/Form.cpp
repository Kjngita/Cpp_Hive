#include "Form.hpp"

Form::Form() : _name("Draft"), _signed(false),
			_grade2sign(150), _grade2exe(149) {
	std::cout << "Default form constructed\n";
}

Form::Form(std::string name, int signGrade, int exeGrade) :
	_name(name), _signed(false),
	_grade2sign(signGrade), _grade2exe(exeGrade) {
	if (_grade2sign < 1 || _grade2exe < 1)
		throw Form::GradeTooHighException();
	if (_grade2sign > 150 || _grade2exe > 150)
		throw Form::GradeTooLowException();
	std::cout << "Proper form constructed\n";
}

Form::Form(const Form& other) :
	_name(other._name), _signed(other._signed),
	_grade2sign(other._grade2sign), _grade2exe(other._grade2exe) {
	std::cout << "Form copied\n";
}

Form::~Form() {
	std::cout << "Form " << _name << " shredded to pieces\n";
}

const std::string	Form::getName() const { return _name; }

std::string	Form::getStatus() const {
	if (_signed)
		return "Signed";
	return "Empty";
}

int	Form::getGrade2Sign() const { return _grade2sign; }

int	Form::getGrade2Exe() const { return _grade2exe; }

std::ostream& operator<<(std::ostream& out, const Form& target) {
	out << "Form name:\t" << target.getName()
		<< "\nStatus:\t\t" << target.getStatus()
		<< "\nSign grade:\t" << target.getGrade2Sign()
		<< "\nExecute grade:\t" << target.getGrade2Exe()
		<< std::endl;
	return out;
}

void	Form::beSigned(const Bureaucrat& guy) {
	if (guy.getGrade() > static_cast<unsigned int>(_grade2sign))
		throw Form::GradeTooLowException();
	else
		_signed = true;
}