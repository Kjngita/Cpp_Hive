#include "PmergeMe.hpp"

int main(int ac, char** av)
{
	if (ac <= 2)
	{
		std::cerr << "Need a sequence of integers to sort\n";
		return 1;
	}

	PmergeMe			sorter;
	std::vector<int>	vec;
	std::deque<int>		deq;
	for (int i = 1; i < ac; i++)
	{
		try
		{
			std::string	numStr = av[i];
			int num = sorter.checkNum(numStr);
			vec.emplace_back(num);
			deq.emplace_back(num);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
	std::cout << "Before:\t";
	for (int i = 1; i < ac; i++) {
		std::cout << av[i] << " ";		
	}
	std::cout << std::endl;

	auto vecStart = std::chrono::high_resolution_clock::now();
	sorter.sortFoJo(vec);
	auto vecDone = std::chrono::high_resolution_clock::now();
	auto vecTime = std::chrono::duration_cast<std::chrono::microseconds>(vecDone - vecStart).count();

	auto deqStart = std::chrono::high_resolution_clock::now();
	sorter.sortFoJo(deq);
	auto deqDone = std::chrono::high_resolution_clock::now();
	auto deqTime = std::chrono::duration_cast<std::chrono::microseconds>(deqDone - deqStart).count();

	if (!sorter.checkContainers(vec, deq))
		return 1;
	
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