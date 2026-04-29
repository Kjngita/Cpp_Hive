#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();
		Intern& operator=(const Intern& other);
		class ExceptionNoForm : public std::exception
		{
			public:
				const char* what() const noexcept override {
					return ("No such form exists");
				}
		};
		AForm*	makeForm(std::string formName, std::string target);
};