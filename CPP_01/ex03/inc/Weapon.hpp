#pragma once

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string _type;
		
	public:
		Weapon();
		Weapon(std::string weapon);
		~Weapon();
		void		setType(std::string new_type);
		std::string	getType();

};