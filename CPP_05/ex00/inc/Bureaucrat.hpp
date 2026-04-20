#pragma once

#include <iostream>

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
		std::string		getName() const;
		unsigned int	getGrade() const;
		void			upGrade();
		void			downGrade();
};