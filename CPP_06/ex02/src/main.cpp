#include "Base.hpp"

int main()
{
	srand(time(nullptr));
	for (int i = 0; i < 5; i++)
	{
		Base*	type = generate();
		std::cout << "Identify using pointer: ";
		identify(type);
		std::cout << "Identify using reference: ";
		identify(*type);
		std::cout << std::endl;
		delete type;
	}
}