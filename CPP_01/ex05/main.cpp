#include "Harl.hpp"

int main()
{
	Harl	dude;
	dude.complain("segfault");
	dude.complain("DEBUG");
	dude.complain("INFO");
	dude.complain("WARNING");
	dude.complain("error");
	return 0;
}