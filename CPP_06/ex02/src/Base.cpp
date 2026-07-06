#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base*	generate() {
	int num = rand() % 3;
	std::cout << "[" << num << "]\n";
	if (num == 0)
		return new A;
	if (num == 1)
		return new B;
	return new C;
}

void	identify(Base* p) {
	//prints the actual type of the object pointed to by p: "A", "B", or "C"
	if (dynamic_cast<A*>(p) != nullptr)
	{
		std::cout << "A\n";
		return;
	}
	else if (dynamic_cast<B*>(p) != nullptr)
	{
		std::cout << "B\n";
		return;
	}
	else if (dynamic_cast<C*>(p) != nullptr)
	{
		std::cout << "C\n";
		return;
	}
	else
		std::cout << "Unknown type, which shouldn't be possible ;_;\n";
}

// void	identify(Base& p) {
// // prints the actual type of the object referenced by p: "A", "B", or "C". Using a pointer
// // inside this function is forbidden
// 	if ()
// }