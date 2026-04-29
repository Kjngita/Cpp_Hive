#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	std::cout << "\t=== Trees ===\n";
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
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	
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
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	// std::cout << "\t=== Creating forms with grades too low ===\n";
	// {
	// 	try
	// 	{
	// 		std::cout << "Params: \"SignLow\", 321654987, 30\n";
	// 		Form	paper("SignLow", 321654987, 30);
	// 		std::cout << paper << std::endl;
	// 	}
	// 	catch(std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// 	try
	// 	{
	// 		std::cout << "Params: \"ExeLow\", 60, 300\n";
	// 		Form	paper("ExeLow", 60, 300);
	// 		std::cout << paper << std::endl;
	// 	}
	// 	catch(std::exception& e)
	// 	{
	// 		std::cerr << e.what() << std::endl;
	// 	}
	// }
	// std::cout << "- - - - - - - - - - - - - - - -\n";
	
	// std::cout << "\t=== Signing papers ===\n";
	// {
	// 	try
	// 	{
	// 		Bureaucrat	p1("Bill", 69);
	// 		Bureaucrat	p2("Bob", 100);
	// 		std::cout << p1 << std::endl;
	// 		std::cout << p2 << std::endl;

	// 		Form	f1("ContractA", 69, 30);
	// 		Form	f2("ContractB", 99, 30);
	// 		std::cout << f1;
	// 		std::cout << f2 << std::endl;
	// 		p1.signForm(f1);
	// 		std::cout << "   Check\n" << f1 << std::endl;
	// 		p2.signForm(f2);
	// 		std::cout << "   Check\n" << f2 << std::endl;
	// 	}
	// 	catch(std::exception& e)
	// 	{
	// 		std::cerr << "In catch block. " << e.what() << std::endl;
	// 	}
	// }

	return 0;
}