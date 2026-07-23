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
			std::vector<int>::iterator it;
			int test = 5;
			std::cout << "  Find " << test << "  ->\t";
			it = easyfind(v, test);
			std::cout << "v has int " << test << std::endl;
			test = 10;
			std::cout << "  Find " << test << "  ->\t";
			it = easyfind(v, test);
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
			std::list<int>::iterator it;
			int test = 23;
			std::cout << "  Find " << test << "  ->\t";
			it = easyfind(l, test);
			std::cout << "l has int " << test << std::endl;
			test = 68;
			std::cout << "  Find " << test << "  ->\t";
			it = easyfind(l, test);
			std::cout << "l has int " << test << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	{
		const std::deque<int> d{};
		std::cout << "\nConst Deque d = {};\n";
		try
		{
			std::deque<int>::const_iterator it;
			int test = 100;
			std::cout << "  Find " << test << "  ->\t";
			it = easyfind(d, test);
			std::cout << "d has int " << test << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
}