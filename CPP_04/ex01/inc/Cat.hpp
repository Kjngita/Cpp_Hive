#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain*	_thoughtsCat;
	
	public:
		Cat();
		Cat(const Cat& other);
		virtual ~Cat();
		Cat& operator=(const Cat& other);

		virtual void	makeSound() const;
		std::string		getThoughts() const;
		void			setThoughts();
};