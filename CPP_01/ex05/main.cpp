#include "Harl.hpp"

int main()
{
	Harl	dude;
	dude.complain("debug");
	dude.complain("info");
	dude.complain("segfault");
	dude.complain("warning");
	dude.complain("error");
	return 0;
}