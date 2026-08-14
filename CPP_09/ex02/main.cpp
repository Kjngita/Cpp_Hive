#include "PmergeMe.hpp"

int	checkNum(std::string numStr)
{
	size_t	pos;
	int num = std::stoi(numStr, &pos);
	if (pos != numStr.length())
		throw std::runtime_error("Not an integer input found");
	if (num < 0)
		throw std::out_of_range("Only positive integers pls");
	return num;
}

int main(int ac, char** av)
{
	if (ac <= 2)
	{
		std::cerr << "Need a sequence of integers to sort\n";
		return 1;
	}

	std::vector<int>	vec;
	std::deque<int>		deq;
	std::cout << "Before:\t";
	for (int i = 1; i < ac; i++)
	{
		try
		{
			std::string	numStr = av[i];
			int num = checkNum(numStr);
			vec.emplace_back(num);
			deq.emplace_back(num);
			std::cout << num << " ";
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
	std::cout << std::endl;

	PmergeMe	sorter;
	auto vecStart = std::chrono::high_resolution_clock::now();
	//sort vec
	auto vecDone = std::chrono::high_resolution_clock::now();
	auto vecTime = std::chrono::duration_cast<std::chrono::microseconds>(vecDone - vecStart).count();

	auto deqStart = std::chrono::high_resolution_clock::now();
	//sort deq
	auto deqDone = std::chrono::high_resolution_clock::now();
	auto deqTime = std::chrono::duration_cast<std::chrono::microseconds>(deqDone - deqStart).count();

	std::cout << "After:\t";
	for (auto &elem : deq) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with "
			<< "std::vector => " << vecTime << " us\n";
	std::cout << "Time to process a range of " << deq.size() << " elements with "
			<< "std::deque => " << deqTime << " us\n";

	return 0;
}