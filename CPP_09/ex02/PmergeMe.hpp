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
		int		insertionPosVec(std::vector<int>& vec, int val, int upperbound);
		void	sortFoJo(std::deque<int>& chain);
		int		insertionPosDeq(std::deque<int>& deq, int value);

		std::vector<int>	optimalOrder(size_t pendSize);
		std::vector<int>	generateJacob(size_t quantity);

};