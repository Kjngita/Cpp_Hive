#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain*	_thoughtsDog;
	
	public:
		Dog();
		Dog(const Dog& other);
		virtual ~Dog();
		Dog& operator=(const Dog& other);

		virtual void	makeSound() const;
		void			setThoughts(std::string text, int index);
		std::string		getThoughts(int index) const;
};