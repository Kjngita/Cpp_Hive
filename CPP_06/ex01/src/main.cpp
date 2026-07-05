#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	std::cout << "\t===== OG gang =====\n";
	Data	barbie;
	std::cout << barbie << std::endl;
	barbie.setStr("Ah ah ah yeah");
	std::cout << barbie << std::endl;
	std::cout << "[ Memory address of OG data struct ] " << &barbie << std::endl;

	// uintptr_t	ken = Serializer::serialize(&barbie);

	return 0;
}