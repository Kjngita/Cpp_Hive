#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Roboto form", 72, 45), _target("none") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("Roboto form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :
	AForm(other), _target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (canExecute(executor))
	{
		std::cout << "/* Brrrrrrt zzzzzzzzzt */\n";
		srand(time(nullptr));
		int num = rand() % 10;
		if (num % 2 == 0)
			std::cout << _target << " has been robotomized @@\n";
		else
			std::cout << "Robotomization failed...\n";
	}	
}