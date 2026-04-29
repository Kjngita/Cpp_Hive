#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& other) { *this = other; }

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other)
	{}
	return *this;
}

AForm*	Intern::makeForm(std::string formName, std::string target) {
	std::string forms[3] = {"Shrubby form", "Roboto form", "President form"};

	int	index = 3;
	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == formName)
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
		case 0:
		{
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		}
		case 1:
		{
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		}
		case 2:
		{
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		}
		default:
			throw ExceptionNoForm();
	}

		

}