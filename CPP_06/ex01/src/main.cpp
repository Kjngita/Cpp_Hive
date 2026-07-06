#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	std::cout << "\t===== OG gang =====\n";
	Data	barbie;
	std::cout << barbie << std::endl;
	barbie.setStr("Ah ah ah yeah");
	std::cout << "[ Memory address of OG Data struct ]\t" << &barbie << std::endl;

	std::cout << "\n\t===== Cast to uintptr_t =====\n";
	uintptr_t	ken = Serializer::serialize(&barbie);
	std::cout << "[ Value of uintptr ]\t\t" << ken << std::endl;
	std::cout << "[ Memory address of uintptr_t ]\t" << &ken << std::endl;

	std::cout << "\n\t===== Cast back to Data pointer =====\n";
	Data*	aqua = Serializer::deserialize(ken);
	std::cout << *aqua << std::endl;
	std::cout << "[ Value of Data pointer ]\t\t" << aqua << " - Same with original struct address\n";
	std::cout << "[ Memory address of Data pointer ]\t" << &aqua << std::endl;

	return 0;
}