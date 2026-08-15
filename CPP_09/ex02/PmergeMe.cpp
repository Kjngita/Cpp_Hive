#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

//shared helper function to generate Jacobsthal sequence
std::vector<int>	PmergeMe::generateJacob(size_t quantity) {
	std::vector<int>	sequence;
	sequence.push_back(0);
	if (quantity > 1)
		sequence.push_back(1);

	while (sequence.size() < quantity) {
		size_t	last = sequence.size() - 1;
		int next = sequence[last] + 2 * sequence[last - 1];
		if (next >= quantity)
			break;
		sequence.push_back(next);
	}
	return sequence;
}

//shared helper function to determine optimal order to insert elements from pend to main
std::vector<int>	PmergeMe::optimalOrder(size_t pendSize) {
	std::vector<int>	jacobSeq = generateJacob(pendSize); // 0 1 1 3 5 
	std::vector<int>	indexOrder;
	std::vector<bool>	usedIndex(pendSize, false);

	for (int x : jacobSeq) {
		if (x > 0 ) {
			int i = x;
			while (i >= 1 && !usedIndex[i]) {
				indexOrder.push_back(i);
				usedIndex[i] = true;
				i--;
			}
		}
	}

	if (indexOrder.size() + 1 < pendSize) {
		for (int i = pendSize - 1; i >= 1; i--) {
			if (!usedIndex[i]) {
				indexOrder.push_back(i);
				usedIndex[i] = true;
			}
		}
	}
	
	return indexOrder; // 1 3 2 5 4 9 8 7 6
}

//Sort using vector
void	PmergeMe::sortFoJo(std::vector<int>& chain)  {
	if (chain.size() <= 1)
		return;
	
	//Pair elements, each pair has smaller int first and bigger int second
	std::vector<std::pair<int, int>>	duo;
	int		oddOneOut = -1;
	for (size_t	i = 0; i < chain.size(); i += 2) {
		int	a = chain[i];
		int b = chain[i+1];
		if (a < b)
			duo.push_back({a,b});
		else
			duo.push_back({b,a});

	}
	if (chain.size() % 2 != 0)
		oddOneOut = chain.back();

	//Spliting pairs to main (bigger ints) and pend (smaller) chains
	std::vector<int>	main;
	std::vector<int>	pendTmp; //will use a rearranged version later
	for (auto &pair : duo) {
		pendTmp.push_back(pair.first);
		main.push_back(pair.second);
	}

	//Recursive splitting on the main chain until there is only one element
	sortFoJo(main);

	//Create official pend chain to align elems with main chain that was sorted at the end from prev recursion
	std::vector<int>	pend;
	for (int mainVal : main) {
		for (auto& pair : duo) {
			if (pair.second == mainVal)
				pend.push_back(pair.first);
		}
	}
	
	//pend[0] was paired with main[0] -> pend[0] < main[0] -> safe to insert
	main.insert(main.begin(), pend[0]);
	
	//Get the best order of index of pend elems, ensures less comparisons when adding to main chain
	std::vector<int>	pendOrder = optimalOrder(pend.size());
	for (int index : pendOrder) {
		int pos = insertionPosVec(main, pend[index], index);
		main.insert(main.begin() + pos, pend[index]);
	}

	if (oddOneOut >= 0) {
		int pos = insertionPosVec(main, oddOneOut, main.size() - 1);
		main.insert(main.begin() + pos, oddOneOut);
	}

	chain = main;
}

int		PmergeMe::insertionPosVec(std::vector<int>& vec, int val, int boundaryPos) {
	int left = 0;
	int right = boundaryPos;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (vec[mid] < val)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

//Sort using deque
void	PmergeMe::sortFoJo(std::deque<int>& chain) {

}

int		PmergeMe::insertionPosDeq(std::deque<int>& deq, int value) {

}
