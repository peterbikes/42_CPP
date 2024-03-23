#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <string>
#include <iostream>
#include <exception>
#include <stack>

// https://www.youtube.com/watch?v=F9eDv-YIOQ0

// U is an std::deque of type <T>
template <typename T, typename U = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
	// canonical orthodox
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& original);
		MutantStack& operator=(const MutantStack& original);

		typedef	typename	U::iterator		iterator;
		iterator	begin();
		iterator	end();
};

#endif // MUTANTSTACK_HPP
// canonical orthodox

template <typename T, typename U>
MutantStack<T, U>::MutantStack()
{
}

template <typename T, typename U>
MutantStack<T, U>::MutantStack(const MutantStack& original) : std::stack<T, U>(original)
{
	*this = original;
}

template <typename T, typename U>
MutantStack<T, U>::~MutantStack()
{
}

template <typename T, typename U>
MutantStack<T, U>& MutantStack<T, U>::operator=(const MutantStack& original)
{
	if (*this == original)
		return *this;
	std::stack<T>::operator=(original);
	return *this;
}

// .begin and .end are member functions of type ::deque

template <typename T, typename U>
typename MutantStack<T, U>::iterator	MutantStack<T, U>::begin()
{
	return this->c.begin();
}

template <typename T, typename U>
typename MutantStack<T, U>::iterator	MutantStack<T, U>::end()
{
	return this->c.end();
}

