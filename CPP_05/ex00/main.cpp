#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	dude("Bud", 150);
	Bureaucrat	guy(dude);

	std::cout << guy.getGrade() << std::endl;

	return 0;
}