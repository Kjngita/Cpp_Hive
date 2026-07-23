#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main()
{
	{
		std::vector<int> v = {1, 22, 786, 5, 90};
		std::cout << "Vector v = {1, 22, 786, 5, 90}\n";
		try
		{
			int test = 5;
			std::cout << "  Find " << test << "  ->\t";
			easyfind(v, test);
			std::cout << "v has int " << test << std::endl;
			test = 10;
			std::cout << "  Find " << test << "  ->\t";
			easyfind(v, test);
			std::cout << "v has int " << test << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::list<int> l = {75, 23, 48};
		std::cout << "\nList l = {75, 23, 48};\n";
		try
		{
			int test = 23;
			std::cout << "  Find " << test << "  ->\t";
			easyfind(l, test);
			std::cout << "l has int " << test << std::endl;
			test = 68;
			std::cout << "  Find " << test << "  ->\t";
			easyfind(l, test);
			std::cout << "l has int " << test << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		std::deque<int> d{};
		std::cout << "\nDeque d = {};\n";
		try
		{
			int test = 100;
			std::cout << "  Find " << test << "  ->\t";
			easyfind(d, test);
			std::cout << "d has int " << test << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}