#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug()
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "Harl cannot debug this\n\n";
}

void	Harl::info()
{
	std::cout << "[ INFO ]\n";
	std::cout << "Harl does not understand this info\n\n";
}

void	Harl::warning()
{
	std::cout << "[ WARNING ]\n";
	std::cout << "Harl hears no warning\n\n";
}

void	Harl::error()
{
	std::cout << "[ ERROR ]\n";
	std::cout << "Harl drowns in errors\n\n";
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
			switch (i)
			{
			case 0:
				(this->*levelFunctions[0])();
				__attribute__ ((fallthrough));
			case 1:
				(this->*levelFunctions[1])();
				__attribute__ ((fallthrough));
			case 2:
				(this->*levelFunctions[2])();
				__attribute__ ((fallthrough));
			case 3:
				(this->*levelFunctions[3])();
				break ;
			}
			return ;
		}
	}
	std::cout << "[ More complaints from Harl about life in general... ]\n";
}