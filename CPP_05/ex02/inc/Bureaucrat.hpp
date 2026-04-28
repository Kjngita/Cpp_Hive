#pragma once

#include <iostream>

class Form;

class	Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& other) = delete;
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override	{
					return ("[ Highest possible grade is 1 ]\n");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override	{
					return ("[ Lowest possible grade is 150 ]\n");
				}
		};
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			upGrade();
		void			downGrade();
		void			signForm(Form& doc);
		virtual void	execute(Bureaucrat const & executor) const;
};

std::ostream&	operator<<(std::ostream& output, const Bureaucrat& target);