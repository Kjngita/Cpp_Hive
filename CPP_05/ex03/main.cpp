#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Intern		servant;
		AForm*		ptr;
		Bureaucrat	master("Almighty", 5);
		
		// ptr = servant.makeForm("Shrubby form", "testtarget");
		// ptr = servant.makeForm("Roboto form", "testtarget");
		// ptr = servant.makeForm("President form", "testtarget");
		ptr = servant.makeForm("Some form", "testtarget");
		std::cout << *ptr << std::endl;
		master.signForm(*ptr);
		master.executeForm(*ptr);
		delete ptr;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return 0;
}