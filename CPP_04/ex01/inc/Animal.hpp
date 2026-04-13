#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();
		Animal& operator=(const Animal& other);
		
		std::string		getType() const;
		virtual void	makeSound() const;
		virtual void	setThoughts();
		virtual std::string getThoughts() const;
};