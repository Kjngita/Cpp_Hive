#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "\t=== Trees ===\n";
	{
		try
		{
			ShrubberyCreationForm	planting("mountain");
			Bureaucrat				b("Bonnie", 145);

			std::cout << b << std::endl;
			std::cout << planting << std::endl;
			b.executeForm(planting);
			b.signForm(planting);
			b.executeForm(planting);
			std::cout << std::endl;
			Bureaucrat				big("Boss", 10);
			big.executeForm(planting);
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "\n- - - - - - - - - - - - - - - -\n";
	
	
	std::cout << "\t=== Bots ===\n";
	{
		try
		{
			RobotomyRequestForm		robo("Cyborg");
			Bureaucrat				b("Bane", 70);

			std::cout << b << std::endl;
			std::cout << robo << std::endl;
			b.executeForm(robo);
			b.signForm(robo);
			b.executeForm(robo);
			std::cout << std::endl;
			Bureaucrat				big("Boss", 10);
			big.executeForm(robo);
			std::cout << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "\n- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Leader ===\n";
	{
		try
		{
			PresidentialPardonForm	f("Obama");
			Bureaucrat				b("Baka", 20);

			std::cout << b << std::endl;
			std::cout << f << std::endl;
			b.executeForm(f);
			b.signForm(f);
			b.executeForm(f);
			std::cout << std::endl;
			Bureaucrat				big("Boss", 1);
			big.executeForm(f);
			std::cout << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	return 0;
}