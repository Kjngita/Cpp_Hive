#include "PmergeMe.hpp"
#include <algorithm>

inline int	checkNum(std::string numStr)
{
	size_t	pos;
	int num = std::stoi(numStr, &pos);
	if (pos != numStr.length())
		throw std::runtime_error("Not an integer input: " + numStr);
	if (num < 0)
		throw std::out_of_range("Not a positive integer: " + numStr);
	return num;
}

inline bool	checkContainers(std::vector<int>& vec, std::deque<int>& deq)
{
	
	if (!std::is_sorted(vec.begin(), vec.end())) {
		std::cerr << "Vector not sorted properly\n";
		return false;
	}
	if (!std::is_sorted(deq.begin(), deq.end())) {
		std::cerr << "Deque not sorted properly\n";
		return false;
	}
	if (vec.size() != deq.size()) {
		std::cerr << "Vec and deq don't have the same number of elements\n";
		return false;
	}
	for (size_t idx = 0; idx < vec.size(); idx++) {
		if (vec[idx] != deq[idx]) {
			std::cerr << "Vec and deq don't have the same elements\n";
			return false;
		}
	}
	return true;
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
	for (int i = 1; i < ac; i++)
	{
		try
		{
			std::string	numStr = av[i];
			int num = checkNum(numStr);
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

	PmergeMe	sorter;
	auto vecStart = std::chrono::high_resolution_clock::now();
	sorter.sortFoJo(vec);
	auto vecDone = std::chrono::high_resolution_clock::now();
	auto vecTime = std::chrono::duration_cast<std::chrono::microseconds>(vecDone - vecStart).count();

	auto deqStart = std::chrono::high_resolution_clock::now();
	sorter.sortFoJo(deq);
	auto deqDone = std::chrono::high_resolution_clock::now();
	auto deqTime = std::chrono::duration_cast<std::chrono::microseconds>(deqDone - deqStart).count();

	if (!checkContainers(vec, deq))
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