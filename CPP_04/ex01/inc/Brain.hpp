#pragma once

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	
	public:
		Brain();
		Brain(const Brain& other);
		~Brain();
		Brain& operator=(const Brain& other);
		void		setIdea(std::string text, int index);
		std::string	getIdea(int	index) const;
};