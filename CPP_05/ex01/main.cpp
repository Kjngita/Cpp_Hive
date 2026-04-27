#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "\t=== Normal + copy constructor, no copy assignment ===\n";
	{
		Form	doc1;
		Form	doc2(doc1);
		Form	doc3("Registration", 45, 22);
		// doc2 = doc3;

		std::cout << doc1 << std::endl;
		std::cout << doc2 << std::endl;
		std::cout << doc3 << std::endl;
	}
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Creating forms with grades too high ===\n";
	{
		try
		{
			std::cout << "Params: \"SignHigh\", 0, 50\n";
			Form	paper("SignHigh", 0, 50);
			std::cout << paper << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Params: \"ExeHigh\", 60, -3\n";
			Form	paper("ExeHigh", 60, -3);
			std::cout << paper << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Creating forms with grades too low ===\n";
	{
		try
		{
			std::cout << "Params: \"SignLow\", 321654987, 30\n";
			Form	paper("SignLow", 321654987, 30);
			std::cout << paper << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			std::cout << "Params: \"ExeLow\", 60, 300\n";
			Form	paper("ExeLow", 60, 300);
			std::cout << paper << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Signing papers ===\n";
	{
		try
		{
			Bureaucrat	p1("Bill", 69);
			Bureaucrat	p2("Bob", 100);
			std::cout << p1 << std::endl;
			std::cout << p2 << std::endl;

			Form	f1("ContractA", 69, 30);
			Form	f2("ContractB", 99, 30);
			std::cout << f1;
			std::cout << f2 << std::endl;
			p1.signForm(f1);
			std::cout << "   Check\n" << f1 << std::endl;
			p2.signForm(f2);
			std::cout << "   Check\n" << f2 << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << "In catch block. " << e.what() << std::endl;
		}
	}

	return 0;
}