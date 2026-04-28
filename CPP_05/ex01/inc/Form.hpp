#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade2sign;
		const int			_grade2exe;
	
	public:
		Form();
		Form(std::string name, int signGrade, int exeGrade);
		Form(const Form& other);
		~Form();
		Form& operator=(const Form& other) = delete;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override {
					return ("[ Grade too high! ]\n");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override {
					return ("[ Grade too low! ]\n");
				}
		};

		const std::string	getName() const;
		bool				getStatus() const;
		int					getGrade2Sign() const;
		int					getGrade2Exe() const;

		void				beSigned(const Bureaucrat& guy);
};

std::ostream& operator<<(std::ostream& out, const Form& target);