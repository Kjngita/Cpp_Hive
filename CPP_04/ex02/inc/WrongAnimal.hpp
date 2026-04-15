#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& other);
		
		std::string		getType() const;
		virtual void	makeSound() const;
};