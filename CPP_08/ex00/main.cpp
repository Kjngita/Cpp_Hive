#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v = {1, 2, 3, 4, 5};
	try
	{
		easyfind(v, 6);
		std::cout << "Vector has 2\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}