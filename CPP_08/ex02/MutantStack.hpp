#pragma once

#include <stack>
#include <iterator>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		~MutantStack();
		MutantStack& operator=(const MutantStack& other);

		using iterator = typename Container::iterator;
		iterator	begin();
		iterator	end();

		using reverse_iterator = typename Container::reverse_iterator;
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		using const_iterator = typename Container::const_iterator;
		const_iterator	cbegin() const;
		const_iterator	cend() const;

		using const_reverse_iterator = typename Container::const_reverse_iterator;
		const_reverse_iterator	crbegin() const;
		const_reverse_iterator	crend() const;

};

#include "MutantStack.tpp"