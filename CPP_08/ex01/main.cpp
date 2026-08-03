#include "Span.hpp"
#include <climits>
#include <ctime>

void	printSpan(Span& s) {
	std::vector<int> arr = s.getArr();
	std::cout << "{ ";
	for (unsigned long i = 0; i < arr.size(); i++) {
		std::cout << arr[i];
		if (i != arr.size() - 1)
			std::cout << ", ";
	}
	std::cout << " }\n";
}

int main()
{
	try
	{
		std::cout << "   ===== SUBJECT MAIN =====\n\n";

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "Subject shortest:\t" << sp.shortestSpan() << std::endl;
		std::cout << "Subject longest:\t" << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

//----------------------------------------------------------------
	
	try
	{
		std::cout << "\n   ===== SIMPLE SPAN =====\n\n";
		
		Span	simp(3);
		simp.addNumber(INT_MIN);
		simp.addNumber(INT_MAX);
		simp.addNumber(00);
		std::cout << "Span simple = ";
		printSpan(simp);
		std::cout << "  simp shortest:\t" << simp.shortestSpan() << std::endl;
		std::cout << "  simp longest:\t\t" << simp.longestSpan() << std::endl;
		try {
			simp.addNumber(544);
		}
		catch (const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}

//----------------------------------------------------------------

	try
	{
		std::cout << "\n   ===== IMPOSSIBLE COMPARISON =====\n\n";

		Span	zero(20);
		std::cout << "[ Empty Span ]\nSpan zero = ";
		printSpan(zero);
		std::cout << "Trying to find zero.shortestSpan()\n\t-> ";
		zero.shortestSpan();
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Span	one(200);
		one.addNumber(68);
		std::cout << "[ Span with 1 element ]\nSpan one = ";
		printSpan(one);
		std::cout << "Trying to find one.longestSpan()\n\t-> ";
		one.longestSpan();
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
//----------------------------------------------------------------
	
	try
	{
		std::cout << "\n   ===== FILL SPAN USING ITERATORS =====\n\n";

		std::vector<int> nums = {1, 2, 3, 4, 5};
		std::cout << "std::vector<int> nums = {1, 2, 3, 4, 5}\n";

		Span half(10);
		std::cout << "[ Span half(10) ]\n";
		std::cout << "\tBefore\thalf = ";
		printSpan(half);
		half.massFill(nums.begin(), nums.end());
		std::cout << "\tAfter\thalf = ";
		printSpan(half);

		Span full(3);
		std::cout << "[ Span full(3) ]\n";
		std::cout << "\tBefore\tfull = ";
		printSpan(full);
		full.massFill(nums.begin(), nums.end());
		std::cout << "\tAfter\tfull = ";
		printSpan(full);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

//----------------------------------------------------------------

	try
	{
		std::cout << "\n   ===== MANY NUMS =====\n\n";

		const unsigned int N = 12000;
		Span bigSpan(N);

		std::vector<int> aLotOfNums;
		aLotOfNums.reserve(N);
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		for (unsigned int i = 0; i < N; ++i) {
			aLotOfNums.push_back(std::rand());
		}

		// std::sort(aLotOfNums.begin(), aLotOfNums.end());
		bigSpan.massFill(aLotOfNums.begin(), aLotOfNums.end());
		// printSpan(bigSpan);
		std::cout << "Shortest span:\t" << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span:\t" << bigSpan.longestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}