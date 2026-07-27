#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
	{
		MutantStack<int>	mstack;
	
		mstack.push(12);
		mstack.push(67);
		std::cout << mstack.top() << std::endl;
	
		MutantStack<int>	copy(mstack);
		MutantStack<int>	assign;
		assign = copy;
		std::cout << "Copy size=" << copy.size() << " top=" << copy.top() << std::endl;
		std::cout << "Assign size=" << assign.size() << " top=" << assign.top() << std::endl;
	}

	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "mstack top " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "mstack size after pop " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		std::cout << "Printing mstack from bottom to top\n";
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}

	{
		std::list<int> testList;
		testList.push_back(5);
		testList.push_front(17);
		std::cout << "testList top " << testList.front() << std::endl;
		testList.pop_front();
		std::cout << "testList size after pop " << testList.size() << std::endl;
		testList.push_front(3);
		testList.push_front(5);
		testList.push_front(737);
		testList.push_front(0);
		std::list<int>::iterator it = testList.begin();
		std::list<int>::iterator ite = testList.end();
		++it;
		--it;
		std::cout << "Printing testList from begin to end(reverse of stack)\n";
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
	}
}