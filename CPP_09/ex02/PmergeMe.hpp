#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>		//for calculating time
#include <algorithm>	//for std::is_sorted in final check

class PmergeMe
{
	private:
		
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other) = delete;
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& other) = delete;
		
		//Utility functions
		int		checkNum(std::string numStr);
		bool	checkContainers(std::vector<int>& vec, std::deque<int>& deq);
		
		//Shared functions
		std::vector<int>	optimalOrder(size_t pendSize);
		std::vector<int>	generateJacob(size_t quantity);

		//Functions for sorting
		void	sortFoJo(std::vector<int>& chain);
		int		insertionPosVec(std::vector<int>& vec, int val, int upperbound);
		void	sortFoJo(std::deque<int>& chain);
		int		insertionPosDeq(std::deque<int>& deq, int val, int boundaryPos);
};