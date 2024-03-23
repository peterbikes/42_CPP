#include "Span.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>

// canonical orthodox

Span::Span() : N(0){}

Span::Span(const Span& original) : vec(original.vec), N(original.N){}

Span& Span::operator=(Span& original)
{
	this->vec = original.vec;
	this->N = original.N;
	
	return (*this);
}

Span::~Span(){}

//special const
Span::Span(unsigned int N) : N(N){}

void	Span::addNumber(int i)
{
	if (this->vec.size() + 1 > N)
		throw std::out_of_range("This Span is Full !\n");
	
	this->vec.push_back(i);
}

void	Span::addHundredRandNumbers()
{
	if (this->vec.size() + 100 > N)
		throw std::out_of_range("This Span can't take 100 more nrs !\n");
		
	int i = -1;
	while(++i < 100)
		this->vec.push_back(rand ());
}

int		Span::longestSpan()
{
	if (this->vec.size() <= 1)
		throw std::out_of_range("Spam needs to have 2 or more numbers\n");
	
	std::vector<int>::iterator min_value = std::min_element(this->vec.begin(), this->vec.end());
    std::vector<int>::iterator max_value = std::max_element(this->vec.begin(), this->vec.end());

    return *max_value - *min_value;
}

int		Span::shortestSpan()
{
	if (this->vec.size() < 2)
		throw std::out_of_range("Spam needs to have 2 or more numbers\n");
	
	int					shortest;

	std::vector<int>	sorted;
	sorted = this->vec;
	sort(sorted.begin(), sorted.end());

	shortest = sorted[1] - sorted[0];

	for (unsigned long i = 1; i < sorted.size() - 1; i++)
	{
		if (sorted[i + 1] - sorted[i] < shortest)
			shortest = sorted[i + 1] - sorted[i];
	}
	
	return shortest;
}
