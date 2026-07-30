#include "Span.hpp"

void	printSpan(Span& s) {
	std::vector<int> arr = s.getArr();
	for (unsigned long i = 0; i < arr.size(); i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		printSpan(sp);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(888);
		std::cout << "Done adding\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}