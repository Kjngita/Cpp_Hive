#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "Harl cannot debug this\n";
}

void	Harl::info()
{
	std::cout << "Harl does not understand this info\n";
}

void	Harl::warning()
{
	std::cout << "Harl hears no warning\n";
}

void	Harl::error()
{
	std::cout << "Harl drowns in errors\n";
}

void	Harl::complain(std::string level)
{
	std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void (Harl::*levelFunctions[])() = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	for (int i = 0; i < 4; i++)
	{
		if (str[i] == level)
		{
			(this->*levelFunctions[i])();
			return ;
		}
	}
}