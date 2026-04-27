#include "Bureaucrat.hpp"

int main()
{
	std::cout << "\t=== Normal + copy constructor, no copy assignment ===\n";
	{
		Bureaucrat	dude("Bud", 68);
		Bureaucrat	guy(dude);
		Bureaucrat	bro;
		// bro = dude;
		
		std::cout << dude << std::endl;
		std::cout << guy << std::endl;
		std::cout << bro << std::endl;
	}
	std::cout << "\n- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Creating one with grade too high ===\n";
	{
		try
		{
			Bureaucrat	genius("Einstein", 0);
			std::cout << genius << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Creating one with grade too low ===\n";
	{
		try
		{
			Bureaucrat	fool("Mr. Bean", 168);
			std::cout << fool << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Increase grade ===\n";
	{
		try
		{
			Bureaucrat	p1("Bam", 15);
			Bureaucrat	p2("Boo", 1);

			std::cout << p1 << std::endl;
			std::cout << p2 << std::endl;
			p1.upGrade();
			std::cout << p1 << std::endl;
			p2.upGrade();
			std::cout << p2 << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "- - - - - - - - - - - - - - - -\n";
	
	std::cout << "\t=== Decrease grade ===\n";
	{
		try
		{
			Bureaucrat	p1("Big", 150);
			Bureaucrat	p2("Ben", 69);

			std::cout << p1 << std::endl;
			std::cout << p2 << std::endl;
			p1.downGrade();
			std::cout << p1 << std::endl;
			p2.downGrade();
			std::cout << p2 << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return 0;
}