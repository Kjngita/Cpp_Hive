#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>	//for calculating time

class PmergeMe
{
	private:
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other) = delete;
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other) = delete;

		void	sortFoJo(std::vector<int>& chain);
		int		binaryInsertion(std::vector<int>& vec, int value);
		void	sortFoJo(std::deque<int>& chain);
		int		binaryInsertion(std::deque<int>& deq, int value);

		std::vector<int>	generateJacob(size_t quantity);
		std::vector<int>	optimalOrder(size_t pendSize);

};