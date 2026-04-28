#include "AForm.hpp"

AForm::AForm() : _name("Draft"), _signed(false),
			_grade2sign(150), _grade2exe(149) {
	std::cout << "Default form constructed\n";
}

AForm::AForm(std::string name, int signGrade, int exeGrade) :
	_name(name), _signed(false),
	_grade2sign(signGrade), _grade2exe(exeGrade) {
	if (_grade2sign < 1 || _grade2exe < 1)
		throw AForm::GradeTooHighException();
	if (_grade2sign > 150 || _grade2exe > 150)
		throw AForm::GradeTooLowException();
	std::cout << "Proper form constructed\n";
}

AForm::AForm(const AForm& other) :
	_name(other._name), _signed(other._signed),
	_grade2sign(other._grade2sign), _grade2exe(other._grade2exe) {
	std::cout << "Form copied\n";
}

AForm::~AForm() {
	std::cout << "Form " << _name << " shredded to pieces\n";
}

const std::string	AForm::getName() const { return _name; }

bool	AForm::getStatus() const {
	if (_signed)
		return "Signed";
	return "Empty";
}

int	AForm::getGrade2Sign() const { return _grade2sign; }

int	AForm::getGrade2Exe() const { return _grade2exe; }

std::ostream& operator<<(std::ostream& out, const AForm& target) {
	std::string	stat = "Empty";
	if (target.getStatus())
		stat = "Signed";

	out << "Form name:\t" << target.getName()
		<< "\nStatus:\t\t" << stat
		<< "\nSign grade:\t" << target.getGrade2Sign()
		<< "\nExecute grade:\t" << target.getGrade2Exe()
		<< std::endl;
	return out;
}

void	AForm::beSigned(const Bureaucrat& guy) {
	if (guy.getGrade() > static_cast<unsigned int>(_grade2sign))
		throw AForm::GradeTooLowException();
	else
		_signed = true;
}

int	AForm::canExecute(const Bureaucrat& man) {
	int	ret = 0;
	if (!getStatus())
		beSigned(man);
	if (man.getGrade() > static_cast<unsigned int>(_grade2exe))
		throw AForm::GradeTooLowException();
	ret = 1;
	return ret;
}