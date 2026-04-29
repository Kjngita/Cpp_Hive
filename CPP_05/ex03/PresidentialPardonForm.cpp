#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("President form", 25, 5), _target("none") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("President form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) :
	AForm(other), _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (canExecute(executor))
	{
		std::cout << _target 
				<< " has been pardoned by Zaphod Beeblebrox\n";
	}
}