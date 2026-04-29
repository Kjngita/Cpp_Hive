#pragma once

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade2sign;
		const int			_grade2exe;
	
	public:
		AForm();
		AForm(std::string name, int signGrade, int exeGrade);
		AForm(const AForm& other);
		virtual ~AForm();
		AForm& operator=(const AForm& other) = delete;
		
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
		class FormUnsigned : public std::exception
		{
			public:
				const char* what() const noexcept override {
					return ("[ Form is unsigned! ]\n");
				}
		};

		const std::string	getName() const;
		bool				getStatus() const;
		int					getGrade2Sign() const;
		int					getGrade2Exe() const;

		void				beSigned(const Bureaucrat& guy);
		bool				canExecute(const Bureaucrat& man) const;
		virtual void 		execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& target);